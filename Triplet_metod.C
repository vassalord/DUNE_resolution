#define Triplet_metod_cxx
#include "Triplet_metod.h"
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

// this bloc finds residual using the triplet method, more information https://inspirehep.net/files/c95c46b5e10066cc9a78fd629b43bf3c


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


void Triplet_metod::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Triplet_metod.C
//      root> Triplet_metod t
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
   
   auto c=new TCanvas();
   c->SetGrid();
   gStyle->SetOptStat(1111);
   gStyle->SetOptFit(1111);

   TH1F *dist = new TH1F("dist","Residual the triplet metod; residual;",100,0,1);

   Long64_t nentries = fChain->GetEntriesFast();
   if (nentries > 300) nentries = 300;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      // here variable are specified, instead HitX can be used any parameter
     
      for (size_t i=0; i < HitX->size() - 2; ++i) 
      { 
        float x1 = HitX->at(i);
        float y1 = HitY->at(i);
        float z1 = HitZ->at(i);

        float x2 = HitX->at(i+1);
        float y2 = HitY->at(i+1);
        float z2 = HitZ->at(i+1);

        float x3 = HitX->at(i+2);
        float y3 = HitY->at(i+2);
        float z3 = HitZ->at(i+2);

        Point3D p1 = {x1,y1,z1};
        Point3D p2 = {x2,y2,z2};
        Point3D p3 = {x3,y3,z3};

        //printf("%f\n", distanceFromLine(p1, p2, p3));  

       float distance = distanceFromLine(p1, p2, p3);
       dist -> Fill(distance);
      }
   }
    
    dist->Draw();
    c->SaveAs(Form("residuals.png"));

return 0;

}

