//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Sep 17 15:12:10 2019 by ROOT version 6.12/06
// from TTree GArAnaTree/GArAnaTree
// found on file: anatree.root
//////////////////////////////////////////////////////////

#ifndef ana2_h
#define ana2_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"

class ana2 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           Run;
   Int_t           SubRun;
   Int_t           Event;
   vector<int>     *NType;
   vector<int>     *CCNC;
   vector<int>     *Mode;
   vector<int>     *InterT;
   vector<float>   *MC_Q2;
   vector<float>   *MC_W;
   vector<float>   *MC_X;
   vector<float>   *MC_Y;
   vector<float>   *MC_Theta;
   vector<float>   *MCVertX;
   vector<float>   *MCVertY;
   vector<float>   *MCVertZ;
   vector<float>   *MCNuPx;
   vector<float>   *MCNuPy;
   vector<float>   *MCNuPz;
   vector<int>     *Gint;
   vector<int>     *TgtPDG;
   vector<float>   *Weight;
   vector<float>   *GT_T;
   vector<int>     *MCTrkID;
   vector<int>     *PDG;
   vector<int>     *Mother;
   vector<int>     *PDGMother;
   vector<float>   *MCPStartX;
   vector<float>   *MCPStartY;
   vector<float>   *MCPStartZ;
   vector<float>   *MCPTime;
   vector<float>   *MCPStartPX;
   vector<float>   *MCPStartPY;
   vector<float>   *MCPStartPZ;
   vector<float>   *MCPEndX;
   vector<float>   *MCPEndY;
   vector<float>   *MCPEndZ;
   vector<float>   *MCPEndPX;
   vector<float>   *MCPEndPY;
   vector<float>   *MCPEndPZ;
   vector<string>  *MCPProc;
   vector<string>  *MCPEndProc;
   vector<float>   *TrajMCPX;
   vector<float>   *TrajMCPY;
   vector<float>   *TrajMCPZ;
   vector<float>   *TrajMCPT;
   vector<float>   *TrajMCPE;
   vector<int>     *TrajMCPIndex;
   UInt_t          SimnHits;
   vector<float>   *SimHitX;
   vector<float>   *SimHitY;
   vector<float>   *SimHitZ;
   vector<float>   *SimHitTime;
   vector<float>   *SimHitEnergy;
   vector<int>     *SimHitTrkID;
   vector<ULong64_t> *SimHitCellID;
   Float_t         SimEnergySum;

   vector<float>   *HitX;
   vector<float>   *HitY;
   vector<float>   *HitZ;
   vector<float>   *HitSig;
   vector<float>   *HitRMS;
   vector<float>   *HitChan;


   vector<float>   *TPCClusterX;
   vector<float>   *TPCClusterY;
   vector<float>   *TPCClusterZ;
   vector<float>   *TPCClusterSig;
   vector<float>   *TPCClusterRMS;
   vector<int>     *TPCClusterTrkIDNumber;
   vector<ULong64_t> *TrackIDNumber;
   vector<float>   *TrackStartX;
   vector<float>   *TrackStartY;
   vector<float>   *TrackStartZ;
   vector<float>   *TrackStartPX;
   vector<float>   *TrackStartPY;
   vector<float>   *TrackStartPZ;
   vector<int>     *TrackStartQ;
   vector<float>   *TrackEndX;
   vector<float>   *TrackEndY;
   vector<float>   *TrackEndZ;
   vector<float>   *TrackEndPX;
   vector<float>   *TrackEndPY;
   vector<float>   *TrackEndPZ;
   vector<int>     *TrackEndQ;
   vector<float>   *TrackLenF;
   vector<float>   *TrackLenB;
   vector<int>     *NTPCClustersOnTrack;
   vector<float>   *TrackAvgIonF;
   vector<float>   *TrackAvgIonB;
   vector<ULong64_t> *VertIDNumber;
   vector<float>   *VertX;
   vector<float>   *VertY;
   vector<float>   *VertZ;
   vector<ULong64_t> *VertT;
   vector<int>     *VertN;
   vector<int>     *VertQ;
   vector<ULong64_t> *VT_VertIDNumber;
   vector<ULong64_t> *VT_TrackIDNumber;
   vector<int>     *VT_TrackEnd;
   UInt_t          ReconHits;
   vector<ULong64_t> *ReconHitIDNumber;
   vector<float>   *RecoHitX;
   vector<float>   *RecoHitY;
   vector<float>   *RecoHitZ;
   vector<float>   *RecoHitTime;
   vector<float>   *RecoHitEnergy;
   vector<ULong64_t> *RecoHitCellID;
   Float_t         RecoEnergySum;
   UInt_t          nCluster;
   vector<ULong64_t> *ClusterIDNumber;
   vector<unsigned int> *ClusterNhits;
   vector<float>   *ClusterEnergy;
   vector<float>   *ClusterX;
   vector<float>   *ClusterY;
   vector<float>   *ClusterZ;
   vector<float>   *ClusterTheta;
   vector<float>   *ClusterPhi;
   vector<float>   *ClusterPID;
   vector<float>   *ClusterMainAxisX;
   vector<float>   *ClusterMainAxisY;
   vector<float>   *ClusterMainAxisZ;
   vector<ULong64_t> *ECALAssn_ClusIDNumber;
   vector<ULong64_t> *ECALAssn_TrackIDNumber;
   vector<int>     *ECALAssn_TrackEnd;
   
   

   // List of branches
   TBranch        *b_Run;   //!
   TBranch        *b_SubRun;   //!
   TBranch        *b_Event;   //!
   TBranch        *b_NType;   //!
   TBranch        *b_CCNC;   //!
   TBranch        *b_Mode;   //!
   TBranch        *b_InterT;   //!
   TBranch        *b_MC_Q2;   //!
   TBranch        *b_MC_W;   //!
   TBranch        *b_MC_X;   //!
   TBranch        *b_MC_Y;   //!
   TBranch        *b_MC_Theta;   //!
   TBranch        *b_MCVertX;   //!
   TBranch        *b_MCVertY;   //!
   TBranch        *b_MCVertZ;   //!
   TBranch        *b_MCNuPx;   //!
   TBranch        *b_MCNuPy;   //!
   TBranch        *b_MCNuPz;   //!
   TBranch        *b_Gint;   //!
   TBranch        *b_TgtPDG;   //!
   TBranch        *b_Weight;   //!
   TBranch        *b_GT_T;   //!
   TBranch        *b_MCTrkID;   //!
   TBranch        *b_PDG;   //!
   TBranch        *b_Mother;   //!
   TBranch        *b_PDGMother;   //!
   TBranch        *b_MCPStartX;   //!
   TBranch        *b_MCPStartY;   //!
   TBranch        *b_MCPStartZ;   //!
   TBranch        *b_MCPTime;   //!
   TBranch        *b_MCPStartPX;   //!
   TBranch        *b_MCPStartPY;   //!
   TBranch        *b_MCPStartPZ;   //!
   TBranch        *b_MCPEndX;   //!
   TBranch        *b_MCPEndY;   //!
   TBranch        *b_MCPEndZ;   //!
   TBranch        *b_MCPEndPX;   //!
   TBranch        *b_MCPEndPY;   //!
   TBranch        *b_MCPEndPZ;   //!
   TBranch        *b_MCPProc;   //!
   TBranch        *b_MCPEndProc;   //!
   TBranch        *b_TrajMCPX;   //!
   TBranch        *b_TrajMCPY;   //!
   TBranch        *b_TrajMCPZ;   //!
   TBranch        *b_TrajMCPT;   //!
   TBranch        *b_TrajMCPE;   //!
   TBranch        *b_TrajMCPIndex;   //!
   TBranch        *b_SimnHits;   //!
   TBranch        *b_SimHitX;   //!
   TBranch        *b_SimHitY;   //!
   TBranch        *b_SimHitZ;   //!
   TBranch        *b_SimHitTime;   //!
   TBranch        *b_SimHitEnergy;   //!
   TBranch        *b_SimHitTrkID;   //!
   TBranch        *b_SimHitCellID;   //!
   TBranch        *b_SimEnergySum;   //!
   TBranch        *b_HitX;   //!
   TBranch        *b_HitY;   //!
   TBranch        *b_HitZ;   //!
   TBranch        *b_HitSig;   //!
   TBranch        *b_HitRMS;   //!
   TBranch        *b_HitChan;   //!

   TBranch        *b_TPCClusterX;   //!
   TBranch        *b_TPCClusterY;   //!
   TBranch        *b_TPCClusterZ;   //!
   TBranch        *b_TPCClusterSig;   //!
   TBranch        *b_TPCClusterRMS;   //!
   TBranch        *b_TPCClusterTrkIDNumber;   //!
   TBranch        *b_TrackIDNumber;   //!
   TBranch        *b_TrackStartX;   //!
   TBranch        *b_TrackStartY;   //!
   TBranch        *b_TrackStartZ;   //!
   TBranch        *b_TrackStartPX;   //!
   TBranch        *b_TrackStartPY;   //!
   TBranch        *b_TrackStartPZ;   //!
   TBranch        *b_TrackStartQ;   //!
   TBranch        *b_TrackEndX;   //!
   TBranch        *b_TrackEndY;   //!
   TBranch        *b_TrackEndZ;   //!
   TBranch        *b_TrackEndPX;   //!
   TBranch        *b_TrackEndPY;   //!
   TBranch        *b_TrackEndPZ;   //!
   TBranch        *b_TrackEndQ;   //!
   TBranch        *b_TrackLenF;   //!
   TBranch        *b_TrackLenB;   //!
   TBranch        *b_NTPCClustersOnTrack;   //!
   TBranch        *b_TrackAvgIonF;   //!
   TBranch        *b_TrackAvgIonB;   //!
   TBranch        *b_VertIDNumber;   //!
   TBranch        *b_VertX;   //!
   TBranch        *b_VertY;   //!
   TBranch        *b_VertZ;   //!
   TBranch        *b_VertT;   //!
   TBranch        *b_VertN;   //!
   TBranch        *b_VertQ;   //!
   TBranch        *b_VT_VertIDNumber;   //!
   TBranch        *b_VT_TrackIDNumber;   //!
   TBranch        *b_VT_TrackEnd;   //!
   TBranch        *b_ReconHits;   //!
   TBranch        *b_ReconHitIDNumber;   //!
   TBranch        *b_RecoHitX;   //!
   TBranch        *b_RecoHitY;   //!
   TBranch        *b_RecoHitZ;   //!
   TBranch        *b_RecoHitTime;   //!
   TBranch        *b_RecoHitEnergy;   //!
   TBranch        *b_RecoHitCellID;   //!
   TBranch        *b_RecoEnergySum;   //!
   TBranch        *b_nCluster;   //!
   TBranch        *b_ClusterIDNumber;   //!
   TBranch        *b_ClusterNhits;   //!
   TBranch        *b_ClusterEnergy;   //!
   TBranch        *b_ClusterX;   //!
   TBranch        *b_ClusterY;   //!
   TBranch        *b_ClusterZ;   //!
   TBranch        *b_ClusterTheta;   //!
   TBranch        *b_ClusterPhi;   //!
   TBranch        *b_ClusterPID;   //!
   TBranch        *b_ClusterMainAxisX;   //!
   TBranch        *b_ClusterMainAxisY;   //!
   TBranch        *b_ClusterMainAxisZ;   //!
   TBranch        *b_ECALAssn_ClusIDNumber;   //!
   TBranch        *b_ECALAssn_TrackIDNumber;   //!
   TBranch        *b_ECALAssn_TrackEnd;   //!

   ana2(TTree *tree=0);
   virtual ~ana2();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef ana2_cxx
ana2::ana2(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("anatree.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("anatree.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("anatree.root:/anatree");
      dir->GetObject("GArAnaTree",tree);

   }
   Init(tree);
}

ana2::~ana2()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ana2::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ana2::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void ana2::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   NType = 0;
   CCNC = 0;
   Mode = 0;
   InterT = 0;
   MC_Q2 = 0;
   MC_W = 0;
   MC_X = 0;
   MC_Y = 0;
   MC_Theta = 0;
   MCVertX = 0;
   MCVertY = 0;
   MCVertZ = 0;
   MCNuPx = 0;
   MCNuPy = 0;
   MCNuPz = 0;
   Gint = 0;
   TgtPDG = 0;
   Weight = 0;
   GT_T = 0;
   MCTrkID = 0;
   PDG = 0;
   Mother = 0;
   PDGMother = 0;
   MCPStartX = 0;
   MCPStartY = 0;
   MCPStartZ = 0;
   MCPTime = 0;
   MCPStartPX = 0;
   MCPStartPY = 0;
   MCPStartPZ = 0;
   MCPEndX = 0;
   MCPEndY = 0;
   MCPEndZ = 0;
   MCPEndPX = 0;
   MCPEndPY = 0;
   MCPEndPZ = 0;
   MCPProc = 0;
   MCPEndProc = 0;
   TrajMCPX = 0;
   TrajMCPY = 0;
   TrajMCPZ = 0;
   TrajMCPT = 0;
   TrajMCPE = 0;
   TrajMCPIndex = 0;
   SimHitX = 0;
   SimHitY = 0;
   SimHitZ = 0;
   SimHitTime = 0;
   SimHitEnergy = 0;
   SimHitTrkID = 0;
   SimHitCellID = 0;
   HitX = 0;
   HitY = 0;
   HitZ = 0;
   HitSig = 0;
   HitRMS = 0;
   HitChan = 0;
   TPCClusterX = 0;
   TPCClusterY = 0;
   TPCClusterZ = 0;
   TPCClusterSig = 0;
   TPCClusterRMS = 0;
   TPCClusterTrkIDNumber = 0;
   TrackIDNumber = 0;
   TrackStartX = 0;
   TrackStartY = 0;
   TrackStartZ = 0;
   TrackStartPX = 0;
   TrackStartPY = 0;
   TrackStartPZ = 0;
   TrackStartQ = 0;
   TrackEndX = 0;
   TrackEndY = 0;
   TrackEndZ = 0;
   TrackEndPX = 0;
   TrackEndPY = 0;
   TrackEndPZ = 0;
   TrackEndQ = 0;
   TrackLenF = 0;
   TrackLenB = 0;
   NTPCClustersOnTrack = 0;
   TrackAvgIonF = 0;
   TrackAvgIonB = 0;
   VertIDNumber = 0;
   VertX = 0;
   VertY = 0;
   VertZ = 0;
   VertT = 0;
   VertN = 0;
   VertQ = 0;
   VT_VertIDNumber = 0;
   VT_TrackIDNumber = 0;
   VT_TrackEnd = 0;
   ReconHitIDNumber = 0;
   RecoHitX = 0;
   RecoHitY = 0;
   RecoHitZ = 0;
   RecoHitTime = 0;
   RecoHitEnergy = 0;
   RecoHitCellID = 0;
   ClusterIDNumber = 0;
   ClusterNhits = 0;
   ClusterEnergy = 0;
   ClusterX = 0;
   ClusterY = 0;
   ClusterZ = 0;
   ClusterTheta = 0;
   ClusterPhi = 0;
   ClusterPID = 0;
   ClusterMainAxisX = 0;
   ClusterMainAxisY = 0;
   ClusterMainAxisZ = 0;
   ECALAssn_ClusIDNumber = 0;
   ECALAssn_TrackIDNumber = 0;
   ECALAssn_TrackEnd = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Run", &Run, &b_Run);
   fChain->SetBranchAddress("SubRun", &SubRun, &b_SubRun);
   fChain->SetBranchAddress("Event", &Event, &b_Event);
   fChain->SetBranchAddress("NType", &NType, &b_NType);
   fChain->SetBranchAddress("CCNC", &CCNC, &b_CCNC);
   fChain->SetBranchAddress("Mode", &Mode, &b_Mode);
   fChain->SetBranchAddress("InterT", &InterT, &b_InterT);
   fChain->SetBranchAddress("MC_Q2", &MC_Q2, &b_MC_Q2);
   fChain->SetBranchAddress("MC_W", &MC_W, &b_MC_W);
   fChain->SetBranchAddress("MC_X", &MC_X, &b_MC_X);
   fChain->SetBranchAddress("MC_Y", &MC_Y, &b_MC_Y);
   fChain->SetBranchAddress("MC_Theta", &MC_Theta, &b_MC_Theta);
   fChain->SetBranchAddress("MCVertX", &MCVertX, &b_MCVertX);
   fChain->SetBranchAddress("MCVertY", &MCVertY, &b_MCVertY);
   fChain->SetBranchAddress("MCVertZ", &MCVertZ, &b_MCVertZ);
   fChain->SetBranchAddress("MCNuPx", &MCNuPx, &b_MCNuPx);
   fChain->SetBranchAddress("MCNuPy", &MCNuPy, &b_MCNuPy);
   fChain->SetBranchAddress("MCNuPz", &MCNuPz, &b_MCNuPz);
   fChain->SetBranchAddress("Gint", &Gint, &b_Gint);
   fChain->SetBranchAddress("TgtPDG", &TgtPDG, &b_TgtPDG);
   fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
   fChain->SetBranchAddress("GT_T", &GT_T, &b_GT_T);
   fChain->SetBranchAddress("MCTrkID", &MCTrkID, &b_MCTrkID);
   fChain->SetBranchAddress("PDG", &PDG, &b_PDG);
   //fChain->SetBranchAddress("Mother", &Mother, &b_Mother);
   fChain->SetBranchAddress("PDGMother", &PDGMother, &b_PDGMother);
   fChain->SetBranchAddress("MCPStartX", &MCPStartX, &b_MCPStartX);
   fChain->SetBranchAddress("MCPStartY", &MCPStartY, &b_MCPStartY);
   fChain->SetBranchAddress("MCPStartZ", &MCPStartZ, &b_MCPStartZ);
   fChain->SetBranchAddress("MCPTime", &MCPTime, &b_MCPTime);
   fChain->SetBranchAddress("MCPStartPX", &MCPStartPX, &b_MCPStartPX);
   fChain->SetBranchAddress("MCPStartPY", &MCPStartPY, &b_MCPStartPY);
   fChain->SetBranchAddress("MCPStartPZ", &MCPStartPZ, &b_MCPStartPZ);
   fChain->SetBranchAddress("MCPEndX", &MCPEndX, &b_MCPEndX);
   fChain->SetBranchAddress("MCPEndY", &MCPEndY, &b_MCPEndY);
   fChain->SetBranchAddress("MCPEndZ", &MCPEndZ, &b_MCPEndZ);
   fChain->SetBranchAddress("MCPEndPX", &MCPEndPX, &b_MCPEndPX);
   fChain->SetBranchAddress("MCPEndPY", &MCPEndPY, &b_MCPEndPY);
   fChain->SetBranchAddress("MCPEndPZ", &MCPEndPZ, &b_MCPEndPZ);
   fChain->SetBranchAddress("MCPProc", &MCPProc, &b_MCPProc);
   fChain->SetBranchAddress("MCPEndProc", &MCPEndProc, &b_MCPEndProc);
   fChain->SetBranchAddress("TrajMCPX", &TrajMCPX, &b_TrajMCPX);
   fChain->SetBranchAddress("TrajMCPY", &TrajMCPY, &b_TrajMCPY);
   fChain->SetBranchAddress("TrajMCPZ", &TrajMCPZ, &b_TrajMCPZ);
   fChain->SetBranchAddress("TrajMCPT", &TrajMCPT, &b_TrajMCPT);
   fChain->SetBranchAddress("TrajMCPE", &TrajMCPE, &b_TrajMCPE);
   fChain->SetBranchAddress("TrajMCPIndex", &TrajMCPIndex, &b_TrajMCPIndex);
   fChain->SetBranchAddress("SimnHits", &SimnHits, &b_SimnHits);
   fChain->SetBranchAddress("SimHitX", &SimHitX, &b_SimHitX);
   fChain->SetBranchAddress("SimHitY", &SimHitY, &b_SimHitY);
   fChain->SetBranchAddress("SimHitZ", &SimHitZ, &b_SimHitZ);
   fChain->SetBranchAddress("SimHitTime", &SimHitTime, &b_SimHitTime);
   fChain->SetBranchAddress("SimHitEnergy", &SimHitEnergy, &b_SimHitEnergy);
   fChain->SetBranchAddress("SimHitTrkID", &SimHitTrkID, &b_SimHitTrkID);
   fChain->SetBranchAddress("SimHitCellID", &SimHitCellID, &b_SimHitCellID);
   fChain->SetBranchAddress("SimEnergySum", &SimEnergySum, &b_SimEnergySum);
   fChain->SetBranchAddress("HitX", &HitX, &b_HitX);
   fChain->SetBranchAddress("HitY", &HitY, &b_HitY);
   fChain->SetBranchAddress("HitZ", &HitZ, &b_HitZ);
   fChain->SetBranchAddress("HitSig", &HitSig, &b_HitSig);
   fChain->SetBranchAddress("HitRMS", &HitRMS, &b_HitRMS);
   fChain->SetBranchAddress("HitChan", &HitChan, &b_HitChan);
   fChain->SetBranchAddress("TPCClusterX", &TPCClusterX, &b_TPCClusterX);
   fChain->SetBranchAddress("TPCClusterY", &TPCClusterY, &b_TPCClusterY);
   fChain->SetBranchAddress("TPCClusterZ", &TPCClusterZ, &b_TPCClusterZ);
   fChain->SetBranchAddress("TPCClusterSig", &TPCClusterSig, &b_TPCClusterSig);
   fChain->SetBranchAddress("TPCClusterRMS", &TPCClusterRMS, &b_TPCClusterRMS);
   fChain->SetBranchAddress("TPCClusterTrkIDNumber", &TPCClusterTrkIDNumber, &b_TPCClusterTrkIDNumber);
   fChain->SetBranchAddress("TrackIDNumber", &TrackIDNumber, &b_TrackIDNumber);
   fChain->SetBranchAddress("TrackStartX", &TrackStartX, &b_TrackStartX);
   fChain->SetBranchAddress("TrackStartY", &TrackStartY, &b_TrackStartY);
   fChain->SetBranchAddress("TrackStartZ", &TrackStartZ, &b_TrackStartZ);
   fChain->SetBranchAddress("TrackStartPX", &TrackStartPX, &b_TrackStartPX);
   fChain->SetBranchAddress("TrackStartPY", &TrackStartPY, &b_TrackStartPY);
   fChain->SetBranchAddress("TrackStartPZ", &TrackStartPZ, &b_TrackStartPZ);
   fChain->SetBranchAddress("TrackStartQ", &TrackStartQ, &b_TrackStartQ);
   fChain->SetBranchAddress("TrackEndX", &TrackEndX, &b_TrackEndX);
   fChain->SetBranchAddress("TrackEndY", &TrackEndY, &b_TrackEndY);
   fChain->SetBranchAddress("TrackEndZ", &TrackEndZ, &b_TrackEndZ);
   fChain->SetBranchAddress("TrackEndPX", &TrackEndPX, &b_TrackEndPX);
   fChain->SetBranchAddress("TrackEndPY", &TrackEndPY, &b_TrackEndPY);
   fChain->SetBranchAddress("TrackEndPZ", &TrackEndPZ, &b_TrackEndPZ);
   fChain->SetBranchAddress("TrackEndQ", &TrackEndQ, &b_TrackEndQ);
   fChain->SetBranchAddress("TrackLenF", &TrackLenF, &b_TrackLenF);
   fChain->SetBranchAddress("TrackLenB", &TrackLenB, &b_TrackLenB);
   fChain->SetBranchAddress("NTPCClustersOnTrack", &NTPCClustersOnTrack, &b_NTPCClustersOnTrack);
   fChain->SetBranchAddress("TrackAvgIonF", &TrackAvgIonF, &b_TrackAvgIonF);
   fChain->SetBranchAddress("TrackAvgIonB", &TrackAvgIonB, &b_TrackAvgIonB);
   fChain->SetBranchAddress("VertIDNumber", &VertIDNumber, &b_VertIDNumber);
   fChain->SetBranchAddress("VertX", &VertX, &b_VertX);
   fChain->SetBranchAddress("VertY", &VertY, &b_VertY);
   fChain->SetBranchAddress("VertZ", &VertZ, &b_VertZ);
   fChain->SetBranchAddress("VertT", &VertT, &b_VertT);
   fChain->SetBranchAddress("VertN", &VertN, &b_VertN);
   fChain->SetBranchAddress("VertQ", &VertQ, &b_VertQ);
   fChain->SetBranchAddress("VT_VertIDNumber", &VT_VertIDNumber, &b_VT_VertIDNumber);
   fChain->SetBranchAddress("VT_TrackIDNumber", &VT_TrackIDNumber, &b_VT_TrackIDNumber);
   fChain->SetBranchAddress("VT_TrackEnd", &VT_TrackEnd, &b_VT_TrackEnd);
   fChain->SetBranchAddress("ReconHits", &ReconHits, &b_ReconHits);
   fChain->SetBranchAddress("ReconHitIDNumber", &ReconHitIDNumber, &b_ReconHitIDNumber);
   fChain->SetBranchAddress("RecoHitX", &RecoHitX, &b_RecoHitX);
   fChain->SetBranchAddress("RecoHitY", &RecoHitY, &b_RecoHitY);
   fChain->SetBranchAddress("RecoHitZ", &RecoHitZ, &b_RecoHitZ);
   fChain->SetBranchAddress("RecoHitTime", &RecoHitTime, &b_RecoHitTime);
   fChain->SetBranchAddress("RecoHitEnergy", &RecoHitEnergy, &b_RecoHitEnergy);
   fChain->SetBranchAddress("RecoHitCellID", &RecoHitCellID, &b_RecoHitCellID);
   fChain->SetBranchAddress("RecoEnergySum", &RecoEnergySum, &b_RecoEnergySum);
   fChain->SetBranchAddress("nCluster", &nCluster, &b_nCluster);
   fChain->SetBranchAddress("ClusterIDNumber", &ClusterIDNumber, &b_ClusterIDNumber);
   fChain->SetBranchAddress("ClusterNhits", &ClusterNhits, &b_ClusterNhits);
   fChain->SetBranchAddress("ClusterEnergy", &ClusterEnergy, &b_ClusterEnergy);
   fChain->SetBranchAddress("ClusterX", &ClusterX, &b_ClusterX);
   fChain->SetBranchAddress("ClusterY", &ClusterY, &b_ClusterY);
   fChain->SetBranchAddress("ClusterZ", &ClusterZ, &b_ClusterZ);
   fChain->SetBranchAddress("ClusterTheta", &ClusterTheta, &b_ClusterTheta);
   fChain->SetBranchAddress("ClusterPhi", &ClusterPhi, &b_ClusterPhi);
   fChain->SetBranchAddress("ClusterPID", &ClusterPID, &b_ClusterPID);
   fChain->SetBranchAddress("ClusterMainAxisX", &ClusterMainAxisX, &b_ClusterMainAxisX);
   fChain->SetBranchAddress("ClusterMainAxisY", &ClusterMainAxisY, &b_ClusterMainAxisY);
   fChain->SetBranchAddress("ClusterMainAxisZ", &ClusterMainAxisZ, &b_ClusterMainAxisZ);
   fChain->SetBranchAddress("ECALAssn_ClusIDNumber", &ECALAssn_ClusIDNumber, &b_ECALAssn_ClusIDNumber);
   fChain->SetBranchAddress("ECALAssn_TrackIDNumber", &ECALAssn_TrackIDNumber, &b_ECALAssn_TrackIDNumber);
   fChain->SetBranchAddress("ECALAssn_TrackEnd", &ECALAssn_TrackEnd, &b_ECALAssn_TrackEnd);
   Notify();
}

Bool_t ana2::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void ana2::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t ana2::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef ana2_cxx
