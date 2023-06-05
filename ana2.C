#define ana2_cxx
#include "ana2.h"
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

Double_t fitf(Double_t *x,Double_t *par) {
      Double_t arg = 0;
      if (par[2]!=0) arg = (x[0] - par[1])/par[2];
      Double_t fitval = par[0]*TMath::Exp(-0.5*arg*arg);
      return fitval;
   }

void ana2::Loop()
{
//   In a ROOT session, you can do:
//      root> .L ana2.C
//      root> ana2 t
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
   if (fChain == 0) return;

   gStyle->SetOptStat(1111);
   gStyle->SetOptFit(1111);

   TH1F *distmag = (TH1F*) new TH1F("distmagall","distmag all;distance (cm);TPC Clusters",100,0,1);
   TH1F *dmhole = (TH1F*) new TH1F("distmaghole","hole-filler;distance (cm);TPC Clusters",100,0,1);

   std::vector<TH1F*> dmangbinall;
   std::vector<TH1F*> dmangbiniroc;
   std::vector<TH1F*> dmangbinioroc;
   std::vector<TH1F*> dmangbinooroc;
   for (int i=0; i<15; ++i)
     {
       TString hname = "distmag";
       hname += i;
       TString htitle;
       TString formatted;
       formatted.Form("%4.1f",0.1*(i));
       htitle += formatted;
       htitle += " < #alpha < ";
       formatted.Form("%4.1f",0.1*(i+1));
       htitle += formatted;
       htitle += ";distance (cm);TPC Clusters";
       TString hti = "ALL ROC ";
       hti += htitle;
       dmangbinall.push_back((TH1F*) new TH1F(hname+"all",hti,100,0,1));
       hti = "IROC ";
       hti += htitle;
       dmangbiniroc.push_back((TH1F*) new TH1F(hname+"iroc",hti,100,0,1));
       hti = "IOROC ";
       hti += htitle;
       dmangbinioroc.push_back((TH1F*) new TH1F(hname+"ioroc",hti,100,0,1));
       hti = "OOROC ";
       hti += htitle;
       dmangbinooroc.push_back((TH1F*) new TH1F(hname+"ooroc",hti,100,0,1));
     }


   Long64_t nentries = fChain->GetEntriesFast();
   //if (nentries > 100) nentries = 100;

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      // for each TPC cluster, find the two closest MCP traj points, and find the distance
      // between the cluster and the line connecting the two MCP traj points.
      // to do -- bin it in the angle of the line connecting the traj points to the pad row
      // 

      TVector3 closest(0,0,0);
      TVector3 second(0,0,0);

      for (size_t i=0; i<TrackTrajectoryFWDX->size(); ++i)
	{
	  TVector3 cluspos(TrackTrajectoryFWDX->at(i),TrackTrajectoryFWDY->at(i),TrackTrajectoryFWDZ->at(i));
	  for (size_t j=0; j<TrajMCPX->size(); ++j)
	    {
	      TVector3 mcpos(TrajMCPX->at(j),TrajMCPY->at(j),TrajMCPZ->at(j));
	      if (j == 0)
	        {
	          closest = mcpos;
	        }
	      if (j == 1) // sort the first two
	        {
		  second = mcpos;
		  float d1 = (closest - cluspos).Mag();
		  float d2 = (second - cluspos).Mag();
		  if (d2 < d1)
		    {
		      TVector3 tmp = closest;
		      closest = second;
		      second = tmp;
		    }
	        }
	      else
		{
		  // swap in the third, either as closest or second closest if it qualifies

		  float d1 = (closest - cluspos).Mag();
		  float d2 = (second - cluspos).Mag();
		  float d3 = (mcpos - cluspos).Mag();

		  if (d3 < d1 && d1 < d2)
		    {
		      TVector3 tmp = closest;
		      closest = mcpos;
		      second = tmp;		      
		    }
		  else if (d1 < d3 && d3 < d2)
		    {
		      second = mcpos;
		    }
		}
	    } // found closest and second-closest MC trajectory points
	  //std::cout << "TPC Cluster: " << std::endl;
	  //std::cout << cluspos.X() << " " << cluspos.Y() << " " << cluspos.Z() << std::endl;
	  //std::cout << "  closest: " << std::endl;
	  //std::cout << closest.X() << " " << closest.Y() << " " << closest.Z() << std::endl;
	  //std::cout << "  second closest: " << std::endl;
	  //std::cout << second.X() << " " << second.Y() << " " << second.Z() << std::endl;

	  TVector3 clusposp = cluspos;
	  clusposp.SetX(0);
	  float clusrad = clusposp.Mag();

	  TVector3 dm = second - closest;
	  float magdm = dm.Mag();
	  TVector3 dmp = dm;
	  dmp.SetX(0);
	  TVector3 closestp = closest;
	  closestp.SetX(0);

	  float magdmp = dmp.Mag();
	  if (magdm > 0)
	    {
	      TVector3 dv = (cluspos - closest);
	      float dist = 0;
	      float magdv = dv.Mag();
	      if (magdv > 0)
	        { 
		  TVector3 dvp = dv;
		  dvp.SetX(0);
		  if (magdmp>0)
		    {
		      dist = (dmp.Cross(dvp)).Mag();
		      dist *= 1.0/magdmp;
		    }
		}
	      distmag->Fill(dist);
	      if (clusrad<84)
		{
		  dmhole->Fill(dist);
		}
	      else
		{
		  float cmagp = closestp.Mag();
		  if ( magdmp*cmagp > 0 )
		    {
		      float dot = TMath::Abs(dmp.Dot(closestp)/(magdmp*cmagp));
		      if (dot > 1) dot=1;
		      float alpha = TMath::Abs(TMath::ACos(dot));
		      //std::cout << "dot: " << dot << " alpha: " << alpha << std::endl;
		      int alphabin = alpha*10;
		      if (alphabin < 15)
			{
			  dmangbinall.at(alphabin)->Fill(dist);
			  if (clusrad < (133.5+1486) && clusrad > (1486 - 133.5))
			    {
  	     	              dmangbiniroc.at(alphabin)->Fill(dist);
			    }
			  else if (clusrad < (200+1486) && clusrad > (1486 - 200))
			    {
  	     	              dmangbinioroc.at(alphabin)->Fill(dist);
			    }
			  else
			    {
  	     	              dmangbinooroc.at(alphabin)->Fill(dist);
			    }
			}
		    }
		}
	    }
	  else
	    {
	      std::cout << "no distance between MC points" << std::endl;
	    }
	}
   }

   TCanvas *mycanvas = (TCanvas*) new TCanvas("canvas","canvas",500,400);
   bool dofits = true;

   TF1 *func = new TF1("fit",fitf,-3,3,3);
   func->SetParNames ("Constant","Mean_value","Sigma");
   func->SetParameter(1,0);
   func->FixParameter(1,0);

   double irocfitwidths[15];
   double irocfiterrs[15];
   double iorocfitwidths[15];
   double iorocfiterrs[15];
   double oorocfitwidths[15];
   double oorocfiterrs[15];
   double xerrors[15];
   double alphalist[15];

   mycanvas->Divide(2,1);
   mycanvas->cd(1);
   if (dofits)
     {
       distmag->Fit("fit");
       dmhole->Fit("fit");
     }
   for (int i=0; i<15; ++i)
     {
       xerrors[i] = 0;
       alphalist[i] = 0.05 + i*0.1;
       if (dofits)
	 {
           dmangbinall.at(i)->Fit("fit");

           dmangbiniroc.at(i)->Fit("fit");
	   irocfitwidths[i] = func->GetParameter(2);
	   irocfiterrs[i] = func->GetParError(2);

           dmangbinioroc.at(i)->Fit("fit");
	   iorocfitwidths[i] = func->GetParameter(2);
	   iorocfiterrs[i] = func->GetParError(2);

           dmangbinooroc.at(i)->Fit("fit");
	   oorocfitwidths[i] = func->GetParameter(2);
	   oorocfiterrs[i] = func->GetParError(2);
	 }
     }
   distmag->Draw();
   mycanvas->cd(2);
   dmhole->Draw();
   mycanvas->Print("inclusivehitresiduals.pdf");
   delete mycanvas;

   mycanvas = (TCanvas*) new TCanvas("angresidcanvas","Residuals by angle",1000,800);

   mycanvas->Divide(5,3);  
   for (int i=0; i<15; ++i)
     {
       mycanvas->cd(i+1);
       dmangbinall.at(i)->Draw();
     }
   mycanvas->Print("allrocangresiduals.pdf");

   for (int i=0; i<15; ++i)
     {
       mycanvas->cd(i+1);
       dmangbiniroc.at(i)->Draw();
     }
   mycanvas->Print("irocangresiduals.pdf");

   for (int i=0; i<15; ++i)
     {
       mycanvas->cd(i+1);
       dmangbinioroc.at(i)->Draw();
     }
   mycanvas->Print("iorocangresiduals.pdf");

   for (int i=0; i<15; ++i)
     {
       mycanvas->cd(i+1);
       dmangbinooroc.at(i)->Draw();
     }
   mycanvas->Print("oorocangresiduals.pdf");

   TCanvas *mycanvas2 = (TCanvas*) new TCanvas("canvas2","canvas2",500,400);

   TGraphErrors *greiroc = (TGraphErrors*) new TGraphErrors(15,alphalist,irocfitwidths,xerrors,irocfiterrs);
   greiroc->SetMarkerColor(1);
   greiroc->SetMarkerStyle(20);
   greiroc->SetTitle(";#alpha (rad);Point Residual Width (cm)");
   greiroc->SetMinimum(0);
   greiroc->SetMaximum(0.4);
   TGraphErrors *greioroc = (TGraphErrors*) new TGraphErrors(15,alphalist,iorocfitwidths,xerrors,iorocfiterrs);
   greioroc->SetMarkerColor(2);
   greioroc->SetMarkerStyle(20);
   greioroc->SetTitle("");
   TGraphErrors *greooroc = (TGraphErrors*) new TGraphErrors(15,alphalist,oorocfitwidths,xerrors,oorocfiterrs);
   greooroc->SetMarkerColor(4);
   greooroc->SetMarkerStyle(20);
   greooroc->SetTitle("");

   greiroc->Draw("AP");
   //greiroc->Print();
   greioroc->Draw("P");
   //greioroc->Print();
   greooroc->Draw("P");
   //greooroc->Print();

   TLegend *legend = (TLegend*) new TLegend(0.13,0.7,0.48,0.88);
   legend->SetHeader("Readout Chamber",""); // option "C" allows to center the header
   legend->AddEntry(greooroc,"OOROC","ep");
   legend->AddEntry(greioroc,"IOROC","ep");
   legend->AddEntry(greiroc,"IROC","ep");
   legend->SetLineColor(0);
   legend->Draw();

   mycanvas2->Print("pointresolutions_byroc.pdf");

}

