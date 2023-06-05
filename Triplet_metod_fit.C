#define Triplet_metod_fit_cxx
#include "Triplet_metod_fit.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TVector3.h>
#include <TH1F.h>
#include <iostream>
#include <TMath.h>
#include <TString.h>
#include <TF1.h>
#include <TGraphErrors.h>
#include <TLegend.h>
#include <math.h>

double fitf(double *x, double *par)
        {
        double arg = 0;
        if (par[2] != 0) arg = (x[0] - par[1])/par[2];
        
        double fitval = par[0]*std::exp(-0.5*arg*arg);
        return fitval;
        }

 
typedef struct {
    float x, y, z;
} Point3D;

Point3D crossProduct(Point3D a, Point3D b) {
    Point3D result = {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
    return result;
}

float dotProduct(Point3D a, Point3D b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float magnitude(Point3D a) {
    return sqrt(dotProduct(a, a));
}

float distanceFromLine(Point3D lineStart, Point3D lineEnd, Point3D point) {
    Point3D line = {
        lineEnd.x - lineStart.x,
        lineEnd.y - lineStart.y,
        lineEnd.z - lineStart.z
    };
    Point3D pointToLineStart = {
        point.x - lineStart.x,
        point.y - lineStart.y,
        point.z - lineStart.z
    };
    Point3D perp = crossProduct(line, pointToLineStart);
    return magnitude(perp) / magnitude(line);
}




void Triplet_metod_fit::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Triplet_metod_fit.C
//      root> Triplet_metod_fit t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   
    TH1F *dist = new TH1F("dist","Residual the triplet metod; residual;",100,0,3);
    TH1F *dist1 = new TH1F("dist1","Residual the triplet metod; residual;",100,0,3);
    TH1F *dist2 = new TH1F("dist2","Residual the triplet metod; residual;",100,0,0.7);
    TH1F *dist3 = new TH1F("dist3","Residual the triplet metod; residual;",100,0,3);
    TH1F *dist4 = new TH1F("dist4","Residual the triplet metod; residual;",100,0,3);
         
   
   Long64_t nentries = fChain->GetEntriesFast();
   //if (nentries > 300) nentries = 300;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      //if (Cut(ientry) < 0) continue;

            
      if (TPCClusterX->size() < 3) continue;
      for (size_t i=0; i < TPCClusterX->size() - 2; ++i) 
      { 
        float x1 = TPCClusterX->at(i);
        float y1 = TPCClusterY->at(i);
        float z1 = TPCClusterZ->at(i);

        float x2 = TPCClusterX->at(i+1);
        float y2 = TPCClusterY->at(i+1);
        float z2 = TPCClusterZ->at(i+1);

        float x3 = TPCClusterX->at(i+2);
        float y3 = TPCClusterY->at(i+2);
        float z3 = TPCClusterZ->at(i+2);

        Point3D p1 = {x1,y1,z1};
        Point3D p2 = {x2,y2,z2};
        Point3D p3 = {x3,y3,z3};

        //printf("%f\n", distanceFromLine(p1, p2, p3));  

       float distance = distanceFromLine(p1, p2, p3);
       dist -> Fill(distance);
       dist1 -> Fill(distance);
       dist2 -> Fill(distance);
       dist3 -> Fill(distance);
       dist4 -> Fill(distance);
      }
   }
        
        TF1 *func = new TF1("fitf",fitf,0,3,3);
        func->SetParameters(3000, -4, 1);
        func->SetParNames("Constant","Mean_value","Sigma");

        TF1 *land = new TF1("land","[0]*TMath::Landau(x,[1],[2])",0,3);
        land->SetParameters(1,1,1);
        land->SetParNames("Constant","Mean_value","Sigma");
        
        Double_t par[9];
       
        

        // for double fit

        TF1 *g1    = new TF1("g1","gaus",0,3.0);
        TF1 *g2    = new TF1("g2","gaus",0,3.0);
        TF1 *total = new TF1("total","gaus(0)+gaus(3)",0,3);
        total->SetParameters(0.1*dist->GetMaximum(),0.1,dist->GetRMS(),0.1*dist->GetMaximum(),0.0,100*dist->GetRMS()); 
        total->SetParNames("Constant_1","Mean_value_1","Sigma_1", "Constant_2","Mean_value_2","Sigma_2");
       
    TCanvas *c = new TCanvas("c","c",900,600);
    c->SetGrid();
    gStyle->SetOptStat();
    gStyle->SetOptFit();
    //gPad->SetLogy(kTRUE);

    //dist->Fit(func,"B");
    //dist->Fit("gaus");
    //dist->Fit(land, "B");
    //dist->Draw();
    //c->SaveAs(Form("residuals_landau.png"));
    //c->SaveAs(Form("residuals_gaus.png"));
  
    //dist->Fit(g1,"R");
    //dist->Fit(g2,"R+");
    //dist->Fit(g3,"R+");
    //g1->GetParameters(&par[0]);
    //g2->GetParameters(&par[3]);
    //g3->GetParameters(&par[6]);
    //total->SetParameters(par);
    //dist->Fit(total, "R+");
    //dist->Draw();
    //c->SaveAs(Form("residuals_double_gaus.png"));

    dist->Fit(total, "M");
    dist->Draw();
    g1->SetParameters(total->GetParameter(0), total->GetParameter(1),total->GetParameter(2));
    g2->SetParameters(total->GetParameter(3), total->GetParameter(4),total->GetParameter(5));
    
    
    g1->SetLineColor(3);
    g2->SetLineColor(4);
    g1->Draw("same");
    g2->Draw("same");

    auto legend = new TLegend(0.3,0.8,0.5,0.9);
    legend->AddEntry("g1","First Gauss with parameters 1","l");
    legend->AddEntry("g2","Second Gauss with parameters 2","l");
    legend->AddEntry(total,"Resulting Gauss","l");
    legend->Draw();
    
    c->SaveAs(Form("residuals_double_gaus.png"));
    //c->SaveAs(Form("residuals_double_gaus_log.png"));

    //TCanvas *c1 = new TCanvas("c1","c1",900,600);
    //dist1->Draw();
    //c1->SaveAs(Form("residuals_g3.png"));

    
    //TCanvas *c2 = new TCanvas("c2","c2",900,600);   
    //dist2->Fit(func,"Q");
    //dist2->Draw();
    //c2->SaveAs(Form("residuals_g07.png"));



    
    //TCanvas *tc = new TCanvas("tc","tc",900,600);
    //tc->cd();  
    //gPad->SetLogy(kTRUE);

  
    //dist3->Draw();
    //tc->SaveAs(Form("residuals_log3.png"));

    //TCanvas *tc1 = new TCanvas("tc1","tc1",900,600);
    //tc1->cd();
    //gPad->SetLogy(kTRUE);  
    //dist3->Fit(land, "Q");
    //dist3->Draw();
    //tc1->SaveAs(Form("residuals_log3_land.png"));


return 0;

}

