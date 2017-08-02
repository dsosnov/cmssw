#ifndef HLTriggerspecialHLTMultipletFilter_h
#define HLTriggerspecialHLTMultipletFilter_h

#include "HLTrigger/HLTcore/interface/HLTFilter.h"
#include "DataFormats/L1Trigger/interface/EGamma.h"
#include "DataFormats/L1Trigger/interface/EtSum.h"
#include "DataFormats/L1Trigger/interface/Jet.h"
#include "DataFormats/L1Trigger/interface/Muon.h"
#include "DataFormats/L1Trigger/interface/Tau.h"
#include "DataFormats/HLTReco/interface/TriggerFilterObjectWithRefs.h"

namespace edm {
  class ConfigurationDescriptions;
}

class HLTMultipletFilter : public HLTFilter {

public:
  explicit HLTMultipletFilter(const edm::ParameterSet&);
  ~HLTMultipletFilter();
  virtual bool hltFilter(edm::Event&, const edm::EventSetup&, trigger::TriggerFilterObjectWithRefs & filterproduct) const override;
  static void fillDescriptions(edm::ConfigurationDescriptions & descriptions);

private:

  template<typename T1>
  int objects(edm::Event&, edm::EDGetTokenT<T1> const&, edm::InputTag const&,
	      int, int) const;

  static const int nobj_=5;
  enum Tyoes {EGamma=0, EtSum=1, Jet=2, Muon=3, Tau=4};
  edm::InputTag hltEGammaSeedLabel_, hltEtSumSeedLabel_;
  edm::InputTag hltJetSeedLabel_,    hltMuonSeedLabel_;
  edm::InputTag hltTauSeedLabel_;
  double        minEta_, maxEta_;
  double        minPhi_, maxPhi_;
  double        minPt_;
  int           minN_;
  bool          flag_[nobj_];
  edm::EDGetTokenT<l1t::EGammaBxCollection> hltEGammaToken_;
  edm::EDGetTokenT<l1t::EtSumBxCollection>  hltEtSumToken_;
  edm::EDGetTokenT<l1t::JetBxCollection>    hltJetToken_;
  edm::EDGetTokenT<l1t::MuonBxCollection>   hltMuonToken_;
  edm::EDGetTokenT<l1t::TauBxCollection>    hltTauToken_;
};

#endif
