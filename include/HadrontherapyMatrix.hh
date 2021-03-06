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
// $Id: HadrontherapyMatrix.hh; May 2005
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

#ifndef HadrontherapyMatrix_H
#define HadrontherapyMatrix_H 1

#include "globals.hh"

// The information: energy deposit and position in the phantom
// is stored in a matrix

class HadrontherapyMatrix 
{
private:
  HadrontherapyMatrix(); //< this is supposed to be a singleton

public:

  ~HadrontherapyMatrix();
 
  static HadrontherapyMatrix* getInstance();
 
 void flush();
 
  void Initialize(); 
  // All the elements of the matrix are initialised to zero
 
  void Fill(G4int i, G4int j, G4int k, G4double energyDeposit);
  // The matrix is filled with the energy deposit 
  // in the element corresponding to the voxel of the phantom where
  // the energy deposit was registered
 
  void TotalEnergyDeposit();
  // Store the information of the matrix in a ntuple and in 
  // a 1D Histogram

private:
  static HadrontherapyMatrix* instance;
  G4int numberVoxelX;
  G4int numberVoxelY;
  G4int numberVoxelZ;
  G4double* matrix;
};
#endif
