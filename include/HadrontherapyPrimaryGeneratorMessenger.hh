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
// $Id: HadrontherapyPrimaryGeneratorMessenger.hh; May 2005
// ----------------------------------------------------------------------------
//                 GEANT 4 - Hadrontherapy example
// ----------------------------------------------------------------------------
// Code developed by:
//
// G.A.P. Cirrone(a)*, F. Di Rosa(a), S. Guatelli(b), G. Russo(a)
// 
// (a) Laboratori Nazionali del Sud 
//     of the National Institute for Nuclear Physics, Catania, Italy
// (b) National Institute for Nuclear Physics Section of Genova, genova, Italy
// 
// * cirrone@lns.infn.it
// ----------------------------------------------------------------------------

#ifndef HadrontherapyPrimaryGeneratorMessenger_h
#define HadrontherapyPrimaryGeneratorMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"

class HadrontherapyPrimaryGeneratorAction;
class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithADouble;

class HadrontherapyPrimaryGeneratorMessenger: public G4UImessenger
{
  public:
    HadrontherapyPrimaryGeneratorMessenger(HadrontherapyPrimaryGeneratorAction*);
   ~HadrontherapyPrimaryGeneratorMessenger();
    
  void SetNewValue(G4UIcommand*, G4String);

 private:
    HadrontherapyPrimaryGeneratorAction* HadrontherapyAction; 
    G4UIdirectory*                    beamParametersDir;
    G4UIdirectory*                    EnergyDir;
    G4UIdirectory*                    particlePositionDir;
    G4UIdirectory*                    MomentumDir;
    G4UIcmdWithADoubleAndUnit*        meanKineticEnergyCmd;    
    G4UIcmdWithADoubleAndUnit*        sigmaEnergyCmd;  
    G4UIcmdWithADoubleAndUnit*        XpositionCmd;   
    G4UIcmdWithADoubleAndUnit*        YpositionCmd; 
    G4UIcmdWithADoubleAndUnit*        ZpositionCmd; 
    G4UIcmdWithADoubleAndUnit*        sigmaYCmd; 
    G4UIcmdWithADoubleAndUnit*        sigmaZCmd; 
    G4UIcmdWithADouble*        sigmaMomentumYCmd; 
    G4UIcmdWithADouble*        sigmaMomentumZCmd; 


};

#endif

