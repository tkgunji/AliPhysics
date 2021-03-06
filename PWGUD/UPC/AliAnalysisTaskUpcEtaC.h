/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
* See cxx source for full Copyright notice */
/* $Id$ */

#ifndef ALIANALYSISTASKUPCETAC_H
#define ALIANALYSISTASKUPCETAC_H

class TClonesArray;
class TTree;
class TH1;
class TH2;
class TList;
class AliPIDResponse;
class AliAODEvent;
class AliESDEvent;
class AliTOFTriggerMask;

#define ntrg 17
#include "AliAnalysisTaskSE.h"

class AliAnalysisTaskUpcEtaC : public AliAnalysisTaskSE {
 public:
  AliAnalysisTaskUpcEtaC();
  AliAnalysisTaskUpcEtaC(const char *name);
  virtual ~AliAnalysisTaskUpcEtaC();

  virtual void Init();
  virtual void UserCreateOutputObjects();
  virtual void UserExec(Option_t *option);
  virtual void RunAODtrig();
  virtual void RunAODhist();
  virtual void RunAODtree();
  virtual void RunAODMC(AliAODEvent *aod);
  virtual void RunAODsystematics(AliAODEvent *aod);
  virtual void RunESDtrig();
  virtual void RunESDhist();
  virtual void RunESDtree();
  virtual void RunESDMC(AliESDEvent *esd);
  virtual void Terminate(Option_t *);
  void SetRunTree(Bool_t runTree){fRunTree = runTree;}
  void SetRunHist(Bool_t runHist){fRunHist = runHist;}
  void SetRunSyst(Bool_t runSyst){fRunSystematics = runSyst;}
  void SetTracking(Int_t tracking){fTracking = tracking;}
  void SetIsMC(Bool_t MC){isMC = MC;}
  void InitSystematics();
  Double_t GetMedian(Double_t *daArray);
  Bool_t CheckMeritCutWinner(int cutChoice, double oldPars[3], double newPars[3]);

 private:
  Int_t fType; // 0 - ESD, 1 - AOD
  Int_t fTracking; //0 - Global, 1 - ITSsa
  Bool_t isMC;
  Bool_t fRunTree; 
  Bool_t fRunHist;
  Bool_t fRunSystematics;
  
  int fMeritCutChoice; //set to 4 by default

  AliPIDResponse *fPIDResponse;
  
  //event tree
  TTree *fEtaCK0sChannelTree;
  TTree *fEtaCTree;
  //tree variables
  Int_t fRunNum;
  UInt_t fPerNum, fOrbNum;
  //trigger
  Bool_t fTrigger[ntrg];
  Bool_t fTriggerInputsMC[ntrg];
  UInt_t fL0inputs, fL1inputs;
  AliTOFTriggerMask *fTOFmask;
  Bool_t fIsPhysicsSelected;

  //PID for EtC->Pi+Pi-K+K- Channel  
  Double_t fPIDTPCMuon[4];
  Double_t fPIDTPCElectron[4];
  Double_t fPIDTPCPion[4];
  Double_t fPIDTPCKaon[4];
  Double_t fPIDTPCProton[4];
  
  Double_t fPIDTOFMuon[4];
  Double_t fPIDTOFElectron[4];
  Double_t fPIDTOFPion[4];
  Double_t fPIDTOFKaon[4];
  Double_t fPIDTOFProton[4];

  //PID for EtC->K0s K+- Pi-+ Channel
  Double_t fPIDTPCMuonPos[4];
  Double_t fPIDTPCElectronPos[4];
  Double_t fPIDTPCPionPos[4];
  Double_t fPIDTPCKaonPos[4];
  Double_t fPIDTPCProtonPos[4];
  
  Double_t fPIDTOFMuonPos[4];
  Double_t fPIDTOFElectronPos[4];
  Double_t fPIDTOFPionPos[4];
  Double_t fPIDTOFKaonPos[4];
  Double_t fPIDTOFProtonPos[4];
 
  Double_t fPIDTPCMuonNeg[4];
  Double_t fPIDTPCElectronNeg[4];
  Double_t fPIDTPCPionNeg[4];
  Double_t fPIDTPCKaonNeg[4];
  Double_t fPIDTPCProtonNeg[4];
  
  Double_t fPIDTOFMuonNeg[4];
  Double_t fPIDTOFElectronNeg[4];
  Double_t fPIDTOFPionNeg[4];
  Double_t fPIDTOFKaonNeg[4];
  Double_t fPIDTOFProtonNeg[4];
  
  Int_t fVtxContrib;
  Double_t fVtxPos[3];
  Double_t fMCVtxPos[3];
  Double_t fVtxErr[3];
  Double_t fVtxChi2,fVtxNDF;
  Double_t fKfVtxPos[3];
  Int_t fSpdVtxContrib;
  Double_t fSpdVtxPos[3];
  
  Bool_t fIsVtxContributor[4];
  
  UShort_t fBCrossNum, fNtracklets, fNLooseTracks;
  //vzero, zdc
  Double_t fZNAenergy, fZNCenergy;
  Double_t fZPAenergy, fZPCenergy;
  Double_t fZDCAtime, fZDCCtime;
  Int_t fV0Adecision, fV0Cdecision;
  Int_t fADAdecision, fADCdecision;
  //input data
  TObjString *fDataFilnam;
  Short_t fRecoPass;
  Long64_t fEvtNum;
  //tracks
  TClonesArray *fJPsiAODTracks;
  TClonesArray *fJPsiESDTracks; 
  TClonesArray *fEtaCAODTracks;
  TClonesArray *fEtaCESDTracks;
    //mc
  TClonesArray *fGenPart;
  
  TList *fListTrig;
  TH1D *fHistCcup4TriggersPerRun;
  TH1D *fHistCcup7TriggersPerRun;
  TH1D *fHistCcup2TriggersPerRun;
  TH1D *fHistCint1TriggersPerRun;
  TH1D *fHistCint6TriggersPerRun;
  TH1D *fHistC0tvxAndCint1TriggersPerRun;
  TH1D *fHistZedTriggersPerRun;
  TH1D *fHistCvlnTriggersPerRun;
  TH1D *fHistMBTriggersPerRun;
  TH1D *fHistCentralTriggersPerRun;
  TH1D *fHistSemiCentralTriggersPerRun;
  
  TH1D *fHistCTest58TriggersPerRun;
  TH1D *fHistCTest59TriggersPerRun;
  TH1D *fHistCTest60TriggersPerRun;
  TH1D *fHistCTest61TriggersPerRun;
  
  TH1D *fHistCcup8TriggersPerRun;
  TH1D *fHistCcup9TriggersPerRun;
  TH1D *fHistCcup10TriggersPerRun;
  TH1D *fHistCcup11TriggersPerRun;
  TH1D *fHistCcup12TriggersPerRun;
  TH1D *fHistCtrueTriggersPerRun;

  //My histos and stuff
  TList *fListHist;

  TH1D *fHistNeventsEtaC; //Count potential EtaC events at each step
  TH2D *fMPiKvsMPiK; //Dalitz Plot, Mass first PiK combo vs Mass second PiK combo
  //2 Kstar case
  TH1D *f2KstarPtPiPlus;
  TH1D *f2KstarPtPiMinus;
  TH1D *f2KstarPtKPlus;
  TH1D *f2KstarPtKMinus;
  TH2D *f2KstarTPCsignalPion; //dEdx correlation Pions
  TH2D *f2KstarTPCsignalKaon; //dEdx correlation Kaons
  TH2D *f2KstarTPCsignalVsQPtPion; //dEdx Pions vs Q*Pt
  TH2D *f2KstarTPCsignalVsQPtKaon; //dEdx Kaons vs Q*Pt
  TH1D *f2KstarPtFirstKstar; 
  TH1D *f2KstarPtSecondKstar;
  TH1D *f2KstarMinvFirstKstar;
  TH1D *f2KstarMinvSecondKstar;
  TH1D *f2KstarPtEtaC;
  TH1D *f2KstarMinvEtaC;
  //1 Kstar case
  TH1D *f1KstarPtPiPlus;
  TH1D *f1KstarPtPiMinus;
  TH1D *f1KstarPtKPlus;
  TH1D *f1KstarPtKMinus;
  TH2D *f1KstarTPCsignalPion; //dEdx correlation Pions
  TH2D *f1KstarTPCsignalKaon; //dEdx correlation Kaons
  TH2D *f1KstarTPCsignalVsQPtPion; //dEdx Pions vs Q*Pt
  TH2D *f1KstarTPCsignalVsQPtKaon; //dEdx Kaons vs Q*Pt
  TH1D *f1KstarPtKstar;
  TH1D *f1KstarPtOtherPiKcombo;
  TH1D *f1KstarMinvKstar;
  TH1D *f1KstarMinvOtherPiKcombo;
  TH1D *f1KstarPtEtaC;
  TH1D *f1KstarMinvEtaC;
  //0 Kstar case
  TH1D *f0KstarPtPiPlus;
  TH1D *f0KstarPtPiMinus;
  TH1D *f0KstarPtKPlus;
  TH1D *f0KstarPtKMinus;
  TH2D *f0KstarTPCsignalPion; //dEdx correlation Pions
  TH2D *f0KstarTPCsignalKaon; //dEdx correlation Kaons
  TH2D *f0KstarTPCsignalVsQPtPion; //dEdx Pions vs Q*Pt
  TH2D *f0KstarTPCsignalVsQPtKaon; //dEdx Kaons vs Q*Pt
  TH1D *f0KstarPtFirstPiKcombo;
  TH1D *f0KstarPtSecondPiKcombo;
  TH1D *f0KstarMinvFirstPiKcombo;
  TH1D *f0KstarMinvSecondPiKcombo;
  TH1D *f0KstarPtEtaC;
  TH1D *f0KstarMinvEtaC;

  //K0s Channel
  TH1D *fHistK0sCandidatesPerEvent; //Track number of K0s candidates per event
  TH1D *fK0sPosDaughterPt;
  TH1D *fK0sNegDaughterPt;
  TH2D *fK0sPosVsNegDaughterPt;
  TH1D *fPionK0sChannelPt;
  TH1D *fKaonK0sChannelPt;
  TH1D *fK0sPt;
  TH1D *fK0sMinv;
  TH1D *fKPiPtK0sChannel;
  TH1D *fKPiMinvK0sChannel;
  TH2D *fMK0sVsMKPiK0sChannel; //Dalitz Plot, Mass K0s vs Mass of PiK combo
  TH1D *fEtaCPtK0sChannel;
  TH1D *fEtaCMinvK0sChannel;
  TH1D *fK0sDecayLength;


  TH2D *fHistEtaCMassVsPt;
  TH1D *fHistEtaCMassCoherent;

  TH1D *fHistNeventsEtaCK0sChannel; //Count potential EtaC events at each step

  //Diagnostic histos to understand what kind of events are being analyzed.
  TH1D *fHistNpion;
  TH1D *fHistNK0sPion;
  TH1D *fHistNkaon;
  TH1D *fHistPiMinusK;

  TH1D *fV0DaughterDca;
  TH1D *fK0sDcaToPrimVertex;
  TH1D *fK0sDaughterDcaToPrimVertex;
  TH1D *fK0sMassDistribution;
  TH1D *fV0DecayLength;
  TH1D *fV0Eta;
  TH1D *fCosPointingAngle;
    
  TH1D *fHistZDCCuts;
  
  TList *fListSystematics;
  TList *fListJPsiLoose;
  TList *fListJPsiTight;
  TList *fListEtaCLoose;
  TList *fListEtaCTight;
  
  AliAnalysisTaskUpcEtaC(const AliAnalysisTaskUpcEtaC&); //not implemented
  AliAnalysisTaskUpcEtaC& operator =(const AliAnalysisTaskUpcEtaC&); //not implemented
  
  ClassDef(AliAnalysisTaskUpcEtaC, 4); 
};

#endif





