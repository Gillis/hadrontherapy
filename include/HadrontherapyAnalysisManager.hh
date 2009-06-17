//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// ----------------------------------------------------------------------------
// $Id: HadrontherapyAnalysisManager.hh; May 2005
// ----------------------------------------------------------------------------
//                 GEANT 4 - Hadrontherapy example
// ----------------------------------------------------------------------------
// Code developed by:
//
// G.A.P. Cirrone(a)*, F. Di Rosa(a), S. Guatelli(b), G. Russo(a)
//
// (a) Laboratori Nazionali del Sud
//     of the INFN, Catania, Italy
// (b) INFN Section of Genova, Genova, Italy
//
// * cirrone@lns.infn.it
// ----------------------------------------------------------------------------

#ifndef HADRONTHERAPYANALYSISMANAGER_HH
#define HADRONTHERAPYANALYSISMANAGER_HH 1

#include "globals.hh"

#ifdef ANALYSIS_USE ///< If we use analysis

#ifdef G4ANALYSIS_USE ///< If analysis is done via AIDA
# include <AIDA/AIDA.h>

namespace AIDA{
  class ITree;
  class IAnalysisFactory;
  class ITreeFactory;
}
#endif

#ifdef G4ROOTANALYSIS_USE ///< If analysis is done directly with ROOT
#include "TROOT.h"
#include "TFile.h"
#include "TNtuple.h"
#include "TH1F.h"
#endif

/**
 * Messenger class for analysis-settings for HadronTherapyAnalysisManager 
 */
class HadrontherapyAnalysisFileMessenger;

/**
 * A class for connecting the simulation to an analysis package.
 */
class HadrontherapyAnalysisManager
{
private:
	/**
	 * Analysis manager is a singleton object (there is only one instance).
	 * The pointer to this object is available through the use of the method getInstance();
	 *
	 * @see getInstance
	 */
  HadrontherapyAnalysisManager();
  
public:
  ~HadrontherapyAnalysisManager();

  /**
   * Get the pointer to the analysis manager.
   */
  static HadrontherapyAnalysisManager* getInstance();

  /**
  * Book the histograms and ntuples in an AIDA or ROOT file.
  */
  void book();
  /**
   * Set name for the analysis file .root (used by macro)
   */
  void SetAnalysisFileName(G4String);
  
  /**
  * Fill the ntuple with the energy deposit in the phantom
  */
  void FillEnergyDeposit(G4int voxelXId, G4int voxelYId, G4int voxelZId,
                         G4double energyDeposit);

  void BraggPeak(G4int, G4double); ///< Fill 1D histogram with the Bragg peak in the phantom

  void SecondaryProtonEnergyDeposit(G4int slice, G4double energy);
  ///< Fill 1D histogram with the energy deposit of secondary protons

   void SecondaryNeutronEnergyDeposit(G4int slice, G4double energy);
  ///< Fill 1D histogram with the energy deposit of secondary neutrons

  void SecondaryAlphaEnergyDeposit(G4int slice, G4double energy);
  ///< Fill 1D histogram with the energy deposit of secondary alpha particles

  void SecondaryGammaEnergyDeposit(G4int slice, G4double energy);
  ///< Fill 1D histogram with the energy deposit of secondary gamma

  void SecondaryElectronEnergyDeposit(G4int slice, G4double energy);
  ///< Fill 1D histogram with the energy deposit of secondary electrons

  void SecondaryTritonEnergyDeposit(G4int slice, G4double energy);
  ///< Fill 1D histogram with the energy deposit of secondary tritons

  void SecondaryDeuteronEnergyDeposit(G4int slice, G4double energy);
  ///< Fill 1D histogram with the energy deposit of secondary deuterons

  void SecondaryPionEnergyDeposit(G4int slice, G4double energy);
  ///< Fill 1D histogram with the energy deposit of secondary pions

  void electronEnergyDistribution(G4double secondaryParticleKineticEnergy);
  ///< Energy distribution of secondary electrons originated in the phantom

  void gammaEnergyDistribution(G4double secondaryParticleKineticEnergy);
  ///< Energy distribution of secondary gamma originated in the phantom

  void deuteronEnergyDistribution(G4double secondaryParticleKineticEnergy);
  ///< Energy distribution of secondary deuterons originated in the phantom

  void tritonEnergyDistribution(G4double secondaryParticleKineticEnergy);
  ///< Energy distribution of secondary tritons originated in the phantom

  void alphaEnergyDistribution(G4double secondaryParticleKineticEnergy);
  ///< Energy distribution of secondary alpha originated in the phantom

  void genericIonInformation(G4int, G4double, G4int, G4double);

  void finish();
  ///< Close the .hbk file with the histograms and the ntuples

#ifdef G4ROOTANALYSIS_USE
private:
  TH1F *createHistogram1D(const TString name, const TString title, int bins, double xmin, double xmax) {
    TH1F *histo = new TH1F(name, title, bins, xmin, xmax);
    histo->SetLineWidth(2);
    return histo;
  }
#endif

private:
  static HadrontherapyAnalysisManager* instance;
  HadrontherapyAnalysisFileMessenger* fMess;
  G4String AnalysisFileName;
#ifdef G4ANALYSIS_USE
  AIDA::IAnalysisFactory* aFact;
  AIDA::ITree* theTree;
  AIDA::IHistogramFactory *histFact;
  AIDA::ITupleFactory *tupFact;
  AIDA::IHistogram1D *h1;
  AIDA::IHistogram1D *h2;
  AIDA::IHistogram1D *h3;
  AIDA::IHistogram1D *h4;
  AIDA::IHistogram1D *h5;
  AIDA::IHistogram1D *h6;
  AIDA::IHistogram1D *h7;
  AIDA::IHistogram1D *h8;
  AIDA::IHistogram1D *h9;
  AIDA::IHistogram1D *h10;
  AIDA::IHistogram1D *h11;
  AIDA::IHistogram1D *h12;
  AIDA::IHistogram1D *h13;
  AIDA::IHistogram1D *h14;
  AIDA::ITuple *ntuple;
  AIDA::ITuple *ionTuple;
#endif
#ifdef G4ROOTANALYSIS_USE
  TFile *theTFile;
  TH1F *th1;
  TH1F *th2;
  TH1F *th3;
  TH1F *th4;
  TH1F *th5;
  TH1F *th6;
  TH1F *th7;
  TH1F *th8;
  TH1F *th9;
  TH1F *th10;
  TH1F *th11;
  TH1F *th12;
  TH1F *th13;
  TH1F *th14;
  TNtuple *theROOTNtuple;
  TNtuple *theROOTIonTuple;
#endif
};
#endif

#endif

