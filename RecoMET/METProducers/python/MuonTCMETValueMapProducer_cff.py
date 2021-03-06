import FWCore.ParameterSet.Config as cms

##____________________________________________________________________________||
muonTCMETValueMapProducer = cms.EDProducer(
    "MuonTCMETValueMapProducer",
    muonInputTag        = cms.InputTag("muons"),
    beamSpotInputTag    = cms.InputTag("offlineBeamSpot"),
    vertexInputTag      = cms.InputTag("offlinePrimaryVertices"),
    rf_type             = cms.int32(1),
    trackAlgos          = cms.vstring("undefAlgorithm", "ctf", "rs", "cosmics", "initialStep", "lowPtTripletStep", "pixelPairStep", "detachedTripletStep"),
    d0_max              = cms.double(0.3),
    pt_min              = cms.double(1.),
    pt_max              = cms.double(100.),
    eta_max             = cms.double(2.65),
    chi2_max            = cms.double(5),
    nhits_min           = cms.double(6),
    ptErr_max           = cms.double(0.2),
    track_quality       = cms.vint32(2),
    track_algos         = cms.vstring(),
    chi2_max_tight      = cms.double(5.),
    nhits_min_tight     = cms.double(9),
    ptErr_max_tight     = cms.double(0.2),
    usePvtxd0           = cms.bool(False),
    d0cuta              = cms.double(0.015),
    d0cutb              = cms.double(0.5),
    d0_muon             = cms.double(0.2),
    muon_dptrel         = cms.double(1),
    pt_muon             = cms.double(10),
    eta_muon            = cms.double(2.5),
    chi2_muon           = cms.double(10),
    nhits_muon          = cms.double(11),
    global_muon         = cms.bool(True),
    tracker_muon        = cms.bool(True),
    deltaR_muon         = cms.double(0.05),
    useCaloMuons        = cms.bool(False),
    muonMinValidStaHits = cms.int32(1),

    nLayers = cms.int32(0),
    nLayersTight = cms.int32(0),
    vertexNdof = cms.int32(4),
    vertexZ = cms.double(15.),
    vertexRho = cms.double(2.),
    vertexMaxDZ = cms.double(0.2),
    maxpt_eta25 = cms.double(0.),
    maxpt_eta20 = cms.double(100.),
    )

##____________________________________________________________________________||
