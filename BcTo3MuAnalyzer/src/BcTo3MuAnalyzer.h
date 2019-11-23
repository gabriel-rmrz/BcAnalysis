#ifndef _BcTo3MuAnalyzer_h
#define _BcTo3MuAnalyzer_h

// system include files
#include <memory>

// user include files 
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "DataFormats/Common/interface/Handle.h"

#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/RecoCandidate/interface/RecoChargedCandidate.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/PatCandidates/interface/GenericParticle.h"

#include "TrackingTools/PatternTools/interface/ClosestApproachInRPhi.h"

#include "TTree.h"
//
// class declaration
//

class BcTo3MuAnalyzer : public edm::EDAnalyzer  {
   public:
      explicit BcTo3MuAnalyzer(const edm::ParameterSet&);
      ~BcTo3MuAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      // ----------member data ---------------------------
      edm::EDGetTokenT<edm::View<pat::Muon>> dimuon_Label;
      edm::EDGetTokenT<edm::View<pat::PackedCandidate>> trakCollection_Label;
      edm::EDGetTokenT<reco::VertexCollection> primaryVertices_Label;
      edm::EDGetTokenT<edm::TriggerResults> triggerResults_Label;
      edm::EDGetTokenT<reco::BeamSpot> BS_Label;

      bool OnlyBest_;
      bool isMC_;
      bool OnlyGen_;
      
      TTree* tree_;
      // Event information
      int run, event, lumiblock;
      
      // Primary vertex
      unsigned int nPrimaryVertices;
      float primaryVertexX, primaryVertexY, primaryVertexZ;
      float primaryVertexXError, primaryVertexYError, primaryVertexZError;
      float primaryVertexXYError, primaryVertexXZError, primaryVertexYZError;

      // Bc particle
      unsigned int nBc;
      std::vector<float> *Bc_chi2;
      std::vector<float> *Bc_vertexProbability;

      std::vector<float> *Bc_decayVertexX, *Bc_decayVertexY, *Bc_decayVertexZ;
      std::vector<double> *Bc_decayVertexXError, *Bc_decayVertexYError, *Bc_decayVertexZError;
      std::vector<double> *Bc_decayVertexYXError, *Bc_decayVertexZXError, *Bc_decayVertexZYError;
      
      std::vector<float> *Bc_mass, *Bc_px, *Bc_py, *Bc_pz;
      std::vector<int> *Bc_charge;

      // J/Psi particles coming from Bc
      std::vector<float> *Bc_jpsi_chi2;
      std::vector<float> *Bc_jpsi_vertexProbability;

      std::vector<float> *Bc_jpsi_mass, *Bc_jpsi_px, *Bc_jpsi_py, *Bc_jpsi_pz;

      // Muons coming from J/Psi
      std::vector<float> *Bc_jpsi_mu1_pt, *Bc_jpsi_mu1_px, *Bc_jpsi_mu1_py, *Bc_jpsi_mu1_pz;
      std::vector<float> *Bc_jpsi_mu2_pt, *Bc_jpsi_mu2_px, *Bc_jpsi_mu2_py, *Bc_jpsi_mu2_pz;
      std::vector<int> *Bc_jpsi_mu1_charge, *Bc_jpsi_mu2_charge;

      // Muon coming from Bc
      unsigned int nMuons;
      std::vector<float> *Bc_mu_px, *Bc_mu_py, *Bc_mu_pz;
      std::vector<float> *Bc_mu_px_noFit, *Bc_mu_py_noFit, *Bc_mu_pz_noFit;
      std::vector<int> *Bc_mu_charge;





























};



#endif