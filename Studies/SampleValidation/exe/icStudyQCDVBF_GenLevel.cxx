// TODO: Description

// ICTools includes
#include "Latex/Table/interface/ICLatexTable.h"
#include "Latex/Table/interface/ICLatexTabular.h"
#include "Latex/Table/interface/ICLatexCaption.h"
#include "Plots/Tools/interface/ICPlotFwd.h"
#include "Plots/Tools/interface/ICPlotCollection.h"
#include "Plots/Style/interface/ICStyle.h"

// ROOT includes
#include "TFile.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TLine.h"
#include "TCanvas.h"
#include "TString.h"

// Standard libraries includes
#include <iostream>
#include <string>
#include <map>

using namespace std;

double getIntegralFullRange(TH1F* plot);
double getIntegralFullRange(TH1D* plot);

ICLatexTabular get_tGenVsReco_met_Areas();
ICLatexTabular get_tGenVsReco_Factor();

int main(int argc, char *argv[]){

  double lumi          = 19500.3;
  string pathRootFiles = "";
  string pathOutput    = "";
  
  // If there are arguments process them
  if(argc>1){
    
    for (int i = 1; i < argc; i++){
      if(string(argv[i])=="-i" || string(argv[i])=="--inputDir"){
        pathRootFiles = argv[i+1]; i++;
      }
      else if(string(argv[i])=="-o" || string(argv[i])=="--outputDir"){
        pathOutput = argv[i+1]; i++;
      }
    }
  }
  
  //_________________________________________
  // Samples to be used
  //_________________________________________
  vector<string> sampleID;

//   sampleID.push_back("Data_MET-2012A-13Jul2012-v1");
//   sampleID.push_back("Data_MET-2012A-06Aug2012-v1");
//   sampleID.push_back("Data_MET-2012B-13Jul2012-v1");
//   sampleID.push_back("Data_MET-2012C-24Aug2012-v1");
//   sampleID.push_back("Data_MET-2012C-11Dec2012-v1");
//   sampleID.push_back("Data_MET-2012C-PromptReco-v2");
//   sampleID.push_back("Data_MET-2012D-PromptReco-v1");

  sampleID.push_back("MC_QCD-Pt-30to50-pythia6");
  sampleID.push_back("MC_QCD-Pt-50to80-pythia6");
  sampleID.push_back("MC_QCD-Pt-80to120-pythia6");
  sampleID.push_back("MC_QCD-Pt-120to170-pythia6");
  sampleID.push_back("MC_QCD-Pt-170to300-pythia6");
  sampleID.push_back("MC_QCD-Pt-300to470-pythia6");
  sampleID.push_back("MC_QCD-Pt-470to600-pythia6");
  sampleID.push_back("MC_QCD-Pt-600to800-pythia6");
  sampleID.push_back("MC_QCD-Pt-800to1000-pythia6");  
  sampleID.push_back("MC_QCD-Pt-1000to1400-pythia6");  
  sampleID.push_back("MC_QCD-Pt-1400to1800-pythia6");
  sampleID.push_back("MC_QCD-Pt-1800-pythia6");
  
//   sampleID.push_back("MC_QCD-Pt-80to120_VBF-MET40");
//   sampleID.push_back("MC_QCD-Pt-120to170_VBF-MET40");
//   sampleID.push_back("MC_QCD-Pt-170to300_VBF-MET40");
//   sampleID.push_back("MC_QCD-Pt-300to470_VBF-MET40");
//   sampleID.push_back("MC_QCD-Pt-470to600_VBF-MET40");
//   
//   // TT
//   sampleID.push_back("MC_TTJets");
// 
//   //powheg samples
//   sampleID.push_back("MC_TT-v1");
//   sampleID.push_back("MC_TT-v2");

  //
//   sampleID.push_back("MC_T-tW");
//   sampleID.push_back("MC_Tbar-tW");
//   sampleID.push_back("MC_SingleT-s-powheg-tauola");
//   sampleID.push_back("MC_SingleTBar-s-powheg-tauola");
//   sampleID.push_back("MC_SingleT-t-powheg-tauola");
//   sampleID.push_back("MC_SingleTBar-t-powheg-tauola");
//   sampleID.push_back("MC_WW-pythia6-tauola");       
//   sampleID.push_back("MC_WZ-pythia6-tauola");       
//   sampleID.push_back("MC_ZZ-pythia6-tauola");        
//   sampleID.push_back("MC_W1JetsToLNu_enu");         
//   sampleID.push_back("MC_W2JetsToLNu_enu");         
//   sampleID.push_back("MC_W3JetsToLNu_enu");         
//   sampleID.push_back("MC_W4JetsToLNu_enu");       
//   sampleID.push_back("MC_WJetsToLNu-v1_enu");       
//   sampleID.push_back("MC_WJetsToLNu-v2_enu");        
//   sampleID.push_back("MC_W1JetsToLNu_munu");        
//   sampleID.push_back("MC_W2JetsToLNu_munu");        
//   sampleID.push_back("MC_W3JetsToLNu_munu");        
//   sampleID.push_back("MC_W4JetsToLNu_munu");      
//   sampleID.push_back("MC_WJetsToLNu-v1_munu");      
//   sampleID.push_back("MC_WJetsToLNu-v2_munu");       
//   sampleID.push_back("MC_W1JetsToLNu_taunu");       
//   sampleID.push_back("MC_W2JetsToLNu_taunu");       
//   sampleID.push_back("MC_W3JetsToLNu_taunu");       
//   sampleID.push_back("MC_W4JetsToLNu_taunu");     
//   sampleID.push_back("MC_WJetsToLNu-v1_taunu");     
//   sampleID.push_back("MC_WJetsToLNu-v2_taunu");    
//   sampleID.push_back("MC_DYJetsToLL");             
//   sampleID.push_back("MC_DY1JetsToLL");             
//   sampleID.push_back("MC_DY2JetsToLL");             
//   sampleID.push_back("MC_DY3JetsToLL");             
//   sampleID.push_back("MC_DY4JetsToLL");  
//   sampleID.push_back("MC_ZJetsToNuNu_100_HT_200");  
//   sampleID.push_back("MC_ZJetsToNuNu_200_HT_400");  
//   sampleID.push_back("MC_ZJetsToNuNu_400_HT_inf");   
//   sampleID.push_back("MC_ZJetsToNuNu_50_HT_100");
//   sampleID.push_back("MC_GJets-HT-200To400-madgraph");
//   sampleID.push_back("MC_GJets-HT-400ToInf-madgraph");
//   sampleID.push_back("MC_VBF_HToZZTo4Nu_M-120");    
//   sampleID.push_back("MC_EWK-Z2j");            
//   sampleID.push_back("MC_EWK-Z2jiglep");             
//   sampleID.push_back("MC_EWK-W2jminus_enu");         
//   sampleID.push_back("MC_EWK-W2jplus_enu");          
//   sampleID.push_back("MC_EWK-W2jminus_munu");        
//   sampleID.push_back("MC_EWK-W2jplus_munu");         
//   sampleID.push_back("MC_EWK-W2jminus_taunu");       
//   sampleID.push_back("MC_EWK-W2jplus_taunu");        
//   sampleID.push_back("MC_WGamma");                   
  
  map<string,TFile*> files;
  for(unsigned i=0; i<sampleID.size(); i++){
    files[sampleID[i]] = new TFile(Form("%s/%s.root",pathRootFiles.c_str(),sampleID[i].c_str()));
  }
      
  //_________________________________________
  map<string,double> xsec;
  xsec["MC_QCD-Pt-30to50-pythia6"]     = 66285328;
  xsec["MC_QCD-Pt-50to80-pythia6"]     =  8148778.0;
  xsec["MC_QCD-Pt-80to120-pythia6"]    =  1033680.0;
  xsec["MC_QCD-Pt-120to170-pythia6"]   =   156293.3;
  xsec["MC_QCD-Pt-170to300-pythia6"]   =    34138.15;
  xsec["MC_QCD-Pt-300to470-pythia6"]   =     1759.549;
  xsec["MC_QCD-Pt-470to600-pythia6"]   =      113.8791;
  xsec["MC_QCD-Pt-600to800-pythia6"]   =       26.9921;
  xsec["MC_QCD-Pt-800to1000-pythia6"]  =        3.550036;
  xsec["MC_QCD-Pt-1000to1400-pythia6"] =        0.737844;
  xsec["MC_QCD-Pt-1400to1800-pythia6"] =        0.03352235;
  xsec["MC_QCD-Pt-1800-pythia6"]       =        0.001829005;
  
  xsec["MC_QCD-Pt-80to120_VBF-MET40"]  =  1033680.0;
  xsec["MC_QCD-Pt-120to170_VBF-MET40"] =   156293.3;
  xsec["MC_QCD-Pt-170to300_VBF-MET40"] =    34138.15;
  xsec["MC_QCD-Pt-300to470_VBF-MET40"] =     1759.549;
  xsec["MC_QCD-Pt-470to600_VBF-MET40"] =      113.8791;

  // MC TTbar
  xsec["MC_TTJets"]                      =  245.8;
  xsec["MC_TT-v1"]                       =  211.0;
  xsec["MC_TT-v2"]                       =  211.0;
  
  // Single top
  xsec["MC_T-tW"]                        =  11.1;
  xsec["MC_Tbar-tW"]                     =  11.1;
  xsec["MC_SingleT-s-powheg-tauola"]     =  3.79;
  xsec["MC_SingleTBar-s-powheg-tauola"]  =  1.76;
  xsec["MC_SingleT-t-powheg-tauola"]     =  56.4;
  xsec["MC_SingleTBar-t-powheg-tauola"]  =  30.7;
  
  // MC Dibosons
  xsec["MC_WW-pythia6-tauola"] = 54.838;
  xsec["MC_WZ-pythia6-tauola"] = 33.21;
  xsec["MC_ZZ-pythia6-tauola"] = 17.654;
  xsec["MC_WGamma"]            = 461.6;
  
  xsec["DYJJ01JetsToLL_M-50_MJJ-200"] =  1.4;

  xsec["MC_W1JetsToLNu_enu"]     = 37509;
  xsec["MC_W2JetsToLNu_enu"]     = 37509;
  xsec["MC_W3JetsToLNu_enu"]     = 37509;
  xsec["MC_W4JetsToLNu_enu"]     = 37509;
  xsec["MC_WJetsToLNu-v1_enu"]   = 37509;
  xsec["MC_WJetsToLNu-v2_enu"]   = 37509;
  xsec["MC_W1JetsToLNu_munu"]    = 37509;
  xsec["MC_W2JetsToLNu_munu"]    = 37509;
  xsec["MC_W3JetsToLNu_munu"]    = 37509;
  xsec["MC_W4JetsToLNu_munu"]    = 37509;
  xsec["MC_WJetsToLNu-v1_munu"]  = 37509;
  xsec["MC_WJetsToLNu-v2_munu"]  = 37509;
  xsec["MC_W1JetsToLNu_taunu"]   = 37509;
  xsec["MC_W2JetsToLNu_taunu"]   = 37509;
  xsec["MC_W3JetsToLNu_taunu"]   = 37509;
  xsec["MC_W4JetsToLNu_taunu"]   = 37509;
  xsec["MC_WJetsToLNu-v1_taunu"] = 37509;
  xsec["MC_WJetsToLNu-v2_taunu"] = 37509;

  xsec["MC_DYJetsToLL"]   =  3503.7;
  xsec["MC_DY1JetsToLL"]  =  3503.7;
  xsec["MC_DY2JetsToLL"]  =  3503.7;
  xsec["MC_DY3JetsToLL"]  =  3503.7;
  xsec["MC_DY4JetsToLL"]  =  3503.7;
  xsec["MC_DYJetsToLL_PtZ-100-madgraph"] =  40.5;

  xsec["MC_ZJetsToNuNu_50_HT_100"]       =  381.2;
  xsec["MC_ZJetsToNuNu_100_HT_200"]      =  160.3;
  xsec["MC_ZJetsToNuNu_200_HT_400"]      =  41.49;
  xsec["MC_ZJetsToNuNu_400_HT_inf"]      =  5.274;
  
  xsec["MC_GJets-HT-200To400-madgraph"]  =  960.5;
  xsec["MC_GJets-HT-400ToInf-madgraph"]  =  107.5;

  // MC VBF Higgs to invisible (signal)
  xsec["MC_VBF_HToZZTo4Nu_M-120"]  =  1.649;
  xsec["MC_VBF_HToZZTo4Nu_M-150"]  =  1.280;
  xsec["MC_VBF_HToZZTo4Nu_M-200"]  =  0.8685;
  xsec["MC_VBF_HToZZTo4Nu_M-300"]  =  0.4408;
  xsec["MC_VBF_HToZZTo4Nu_M-400"]  =  0.2543;

  // MC VBF Higgs to invisible POWHEG (signal)
  xsec["MC_Powheg-Htoinv-mH110"]  =  1.809;
  xsec["MC_Powheg-Htoinv-mH125"]  =  1.578;
  xsec["MC_Powheg-Htoinv-mH150"]  =  1.280;
  xsec["MC_Powheg-Htoinv-mH200"]  =  0.8685;
  xsec["MC_Powheg-Htoinv-mH300"]  =  0.4408;
  xsec["MC_Powheg-Htoinv-mH400"]  =  0.2543;

  xsec["MC_EWK-Z2j"]            =  0.888;
  xsec["MC_EWK-Z2jiglep"]       =  1.776;
  xsec["MC_EWK-W2jminus"]       =  4.09;
  xsec["MC_EWK-W2jplus"]        =  6.48;
  xsec["MC_EWK-W2jminus_enu"]   =  4.09;
  xsec["MC_EWK-W2jplus_enu"]    =  6.48;
  xsec["MC_EWK-W2jminus_munu"]  =  4.09;
  xsec["MC_EWK-W2jplus_munu"]   =  6.48;
  xsec["MC_EWK-W2jminus_taunu"] =  4.09;
  xsec["MC_EWK-W2jplus_taunu"]  =  6.48;  
  
  //_________________________________________
  map<string,double> events;  
  events["MC_QCD-Pt-30to50-pythia6"]     = 5910000.0;
  events["MC_QCD-Pt-50to80-pythia6"]     = 5998860.0;
  events["MC_QCD-Pt-80to120-pythia6"]    = 5994864.0;
  events["MC_QCD-Pt-120to170-pythia6"]   = 5955732.0;
  events["MC_QCD-Pt-170to300-pythia6"]   = 5814398.0;
  events["MC_QCD-Pt-300to470-pythia6"]   = 5978500.0;
  events["MC_QCD-Pt-470to600-pythia6"]   = 3964848.0;
  events["MC_QCD-Pt-600to800-pythia6"]   = 3996864.0;
  events["MC_QCD-Pt-800to1000-pythia6"]  = 3998563.0;
  events["MC_QCD-Pt-1000to1400-pythia6"] = 1904088.0;
  events["MC_QCD-Pt-1400to1800-pythia6"] = 1910062.0;
  events["MC_QCD-Pt-1800-pythia6"]       =  947586.0;
   
  events["MC_QCD-Pt-80to120_VBF-MET40"]  = 39376000000;
  events["MC_QCD-Pt-120to170_VBF-MET40"] =  7000000000;
  events["MC_QCD-Pt-170to300_VBF-MET40"] =  1375000000;
  events["MC_QCD-Pt-300to470_VBF-MET40"] =    80000000;
  events["MC_QCD-Pt-470to600_VBF-MET40"] =    25000000;

  events["MC_TTJets"] =  6923750.0;
  events["MC_TT-v1"]  =  28150723;
  events["MC_TT-v2"]  =  28150723;

  events["MC_T-tW"]    =  497658.0;
  events["MC_Tbar-tW"] =  493460.0;
  
  events["MC_SingleT-s-powheg-tauola"]    =  259961.0;
  events["MC_SingleT-t-powheg-tauola"]    =  3758227.0;
  events["MC_SingleTBar-s-powheg-tauola"] =  139974.0;
  events["MC_SingleTBar-t-powheg-tauola"] =  1935072.0;

  events["MC_WW-pythia6-tauola"]           =  10000431.0;
  events["MC_WZ-pythia6-tauola"]           =  10000283.0;
  events["MC_ZZ-pythia6-tauola"]           =  9799908.0;
  events["MC_DYJJ01JetsToLL_M-50_MJJ-200"] =  510501.0;

  events["MC_W1JetsToLNu_enu"]     =  76102995.0;
  events["MC_W2JetsToLNu_enu"]     =  76102995.0;
  events["MC_W3JetsToLNu_enu"]     =  76102995.0;
  events["MC_W4JetsToLNu_enu"]     =  76102995.0;
  events["MC_WJetsToLNu-v1_enu"]   =  76102995.0;
  events["MC_WJetsToLNu-v2_enu"]   =  76102995.0;
  events["MC_W1JetsToLNu_munu"]    =  76102995.0;
  events["MC_W2JetsToLNu_munu"]    =  76102995.0;
  events["MC_W3JetsToLNu_munu"]    =  76102995.0;
  events["MC_W4JetsToLNu_munu"]    =  76102995.0;
  events["MC_WJetsToLNu-v1_munu"]  =  76102995.0;
  events["MC_WJetsToLNu-v2_munu"]  =  76102995.0;
  events["MC_W1JetsToLNu_taunu"]   =  76102995.0;
  events["MC_W2JetsToLNu_taunu"]   =  76102995.0;
  events["MC_W3JetsToLNu_taunu"]   =  76102995.0;
  events["MC_W4JetsToLNu_taunu"]   =  76102995.0;
  events["MC_WJetsToLNu-v1_taunu"] =  76102995.0;
  events["MC_WJetsToLNu-v2_taunu"] =  76102995.0;
  
  events["MC_DYJetsToLL"]                  =  30459503.0;
  events["MC_DY1JetsToLL"]                 =  30459503.0;
  events["MC_DY2JetsToLL"]                 =  30459503.0;
  events["MC_DY3JetsToLL"]                 =  30459503.0;
  events["MC_DY4JetsToLL"]                 =  30459503.0;
  events["MC_DYJetsToLL_PtZ-100-madgraph"] =  2632137.0;
  
  events["MC_ZJetsToNuNu_50_HT_100"]  =  4040980.0;
  events["MC_ZJetsToNuNu_100_HT_200"] =  4416646.0;
  events["MC_ZJetsToNuNu_200_HT_400"] =  5055885.0;
  events["MC_ZJetsToNuNu_400_HT_inf"] =  1006928.0;

  events["MC_GJets-HT-200To400-madgraph"] =  58597147.0;
  events["MC_GJets-HT-400ToInf-madgraph"] =  42391678.0;

  events["MC_VBF_HToZZTo4Nu_M-120"] =  100118.0;
  events["MC_VBF_HToZZTo4Nu_M-150"] =  100280.0;
  events["MC_VBF_HToZZTo4Nu_M-200"] =  100118.0;
  events["MC_VBF_HToZZTo4Nu_M-300"] =  100076.0;
  events["MC_VBF_HToZZTo4Nu_M-400"] =  100083.0;

  events["Powheg-Htoinv-mH110"] =  99885.0;
  events["Powheg-Htoinv-mH125"] =  99885.0;
  events["Powheg-Htoinv-mH150"] =  99874.0;
  events["Powheg-Htoinv-mH200"] =  49922.0;
  events["Powheg-Htoinv-mH300"] =  49945.0;
  events["Powheg-Htoinv-mH400"] =  49964.0;

  events["MC_EWK-Z2j"]            =  2978717;
  events["MC_EWK-Z2jiglep"]       =  2978717;
  events["MC_EWK-W2jminus"]       =  4696648;
  events["MC_EWK-W2jminus_enu"]   =  4696648;
  events["MC_EWK-W2jminus_munu"]  =  4696648;
  events["MC_EWK-W2jminus_taunu"] =  4696648;
  events["MC_EWK-W2jplus"]        =  6776164;
  events["MC_EWK-W2jplus_enu"]    =  6776164;
  events["MC_EWK-W2jplus_munu"]   =  6776164;
  events["MC_EWK-W2jplus_taunu"]  =  6776164;
  
  events["MC_WGamma"] =  4772358;
    
  // 
  map<string,double> wgt; 
  for(map<string,TFile*>::iterator i=files.begin(); i!=files.end(); i++){
    
    string s = i->first;
    if(xsec.find(s) == xsec.end()){
      cout << "Warning: Did not find xsec for weight calculation: " << s << endl;
      continue;
    } 
    if(events.find(s) == events.end()){
      cout << "Warning: Did not find event count for weight calculation: " << s << endl;
      continue;
    } 
    
    wgt[s] = (lumi*xsec[s])/events[s];    
  }
  
  //_________________________________________________________________________________________________    
  // Samples to add
  //_________________________________________________________________________________________________

  vector<string> samples_QCDIncCompare;
  samples_QCDIncCompare.push_back("MC_QCD-Pt-80to120-pythia6"); 
  samples_QCDIncCompare.push_back("MC_QCD-Pt-120to170-pythia6");
  samples_QCDIncCompare.push_back("MC_QCD-Pt-170to300-pythia6");  
  samples_QCDIncCompare.push_back("MC_QCD-Pt-300to470-pythia6");  
  samples_QCDIncCompare.push_back("MC_QCD-Pt-470to600-pythia6");
  
  vector<string> samples_qcdinc;
  samples_qcdinc.push_back("MC_QCD-Pt-30to50-pythia6");
  samples_qcdinc.push_back("MC_QCD-Pt-50to80-pythia6");    
  samples_qcdinc.push_back("MC_QCD-Pt-80to120-pythia6");   
  samples_qcdinc.push_back("MC_QCD-Pt-120to170-pythia6");  
  samples_qcdinc.push_back("MC_QCD-Pt-170to300-pythia6"); 
  samples_qcdinc.push_back("MC_QCD-Pt-300to470-pythia6"); 
  samples_qcdinc.push_back("MC_QCD-Pt-470to600-pythia6"); 
  samples_qcdinc.push_back("MC_QCD-Pt-600to800-pythia6"); 
  samples_qcdinc.push_back("MC_QCD-Pt-800to1000-pythia6"); 
  samples_qcdinc.push_back("MC_QCD-Pt-1000to1400-pythia6");
  samples_qcdinc.push_back("MC_QCD-Pt-1400to1800-pythia6");
  samples_qcdinc.push_back("MC_QCD-Pt-1800-pythia6");    

  //_________________________________________________________________________________________________    
  // Making plots
  //_________________________________________________________________________________________________  

  ICStyle myStyle;
  myStyle.setTDRStyle();
  
  TCanvas *canv = new TCanvas();
  canv->SetLogz();
  
  ICLatexTabular tGenVsReco_met_Areas = get_tGenVsReco_met_Areas();
  ICLatexTabular tGenVsReco_Factor    = get_tGenVsReco_Factor();
  
  MapString_ICH2D mPlots = MapString_ICH2D(files,"GenLevel/genVsReco_met");
  mPlots.scale(wgt);
  mPlots.setXaxisTitle("Gen Met [GeV]");
  mPlots.setYaxisTitle("Reco PFMet Met [GeV]");
  
  TLine horLine( 0,130,500,130); horLine.SetLineColor(kBlue); horLine.SetLineWidth(3);
  TLine verLine(40,  0, 40,500); verLine.SetLineColor(kRed);  verLine.SetLineWidth(3);
  
  TH2D *h0 = new TH2D("test","test",250,0,500,250,0,500);
  h0->GetXaxis()->SetTitle("Gen Met [GeV]");
  h0->GetYaxis()->SetTitle("Reco PFMet Met [GeV]");
  h0->Draw();
  horLine.Draw();
  verLine.Draw();
  canv->SaveAs("basic.png");
  delete h0;
  
  double xBinSize = mPlots["MC_QCD-Pt-30to50-pythia6"]->GetXaxis()->GetBinWidth(1);
  double yBinSize = mPlots["MC_QCD-Pt-30to50-pythia6"]->GetYaxis()->GetBinWidth(1);
  
  // Determining the intersection point
  int binX = int( 40/xBinSize);
  int binY = int(130/yBinSize);
  
  for(unsigned i=0; i<samples_qcdinc.size(); i++){

    canv->SetLogz(true); 
    string *s = &(samples_qcdinc[i]);
    TH2D   *p = mPlots[(*s)];
    
    p->Draw("colz");
    horLine.Draw();
    verLine.Draw();
    canv->SaveAs(Form("%s_GenVsReco_met.pdf",s->c_str()));
    
    double A   = p->Integral(     0,            binX,binY+1,p->GetNbinsY()+1);  
    double B   = p->Integral(binX+1,p->GetNbinsX()+1,binY+1,p->GetNbinsY()+1);      
    double C   = p->Integral(     0,            binX,     0,            binY);
    double D   = p->Integral(binX+1,p->GetNbinsX()+1,     0,            binY);  
    double Tot = p->Integral(     0,p->GetNbinsX()+1,     0,p->GetNbinsY()+1);  
    
    tGenVsReco_met_Areas.setCellContent(i+1, 0,s->c_str());
    tGenVsReco_met_Areas.setCellContent(i+1, 1,A/Tot);
    tGenVsReco_met_Areas.setCellContent(i+1, 2,B/Tot);
    tGenVsReco_met_Areas.setCellContent(i+1, 3,C/Tot);
    tGenVsReco_met_Areas.setCellContent(i+1, 4,D/Tot);
    tGenVsReco_met_Areas.setCellContent(i+1, 5,(A+B)/B);

    TH1D *h = new TH1D(Form("%s_RecoMET_Factor",s->c_str()),Form("%s_RecoMET_Factor",s->c_str()),p->GetNbinsY(),0,250);
    h->GetXaxis()->SetTitle("Reco PFMet Met [GeV]");
    h->GetYaxis()->SetTitle("Normalization Factor");
    

    bool done1p25 = false;
    bool done1p5  = false;
    bool done2p0  = false;
    bool done3p0  = false;

    for(int bin=0; bin<p->GetNbinsY()+2; bin++){

      A = p->Integral(     0,            binX,bin,p->GetNbinsY()+1);  
      B = p->Integral(binX+1,p->GetNbinsX()+1,bin,p->GetNbinsY()+1);            
      
      double factor = (A+B)/B;
      
      if(B>0){h->SetBinContent(bin,factor);}
      else   {h->SetBinContent(bin,0);}

    }
    
    h->Draw();
    horLine.Draw();
    canv->SaveAs(Form("%s.pdf",h->GetName()));
    
    delete h;

    canv->SetLogz(false);
    canv->SetLogy(true);
    h = new TH1D(Form("%s_GenMet_Factor",s->c_str()),Form("%s_GenMet_Factor",s->c_str()),p->GetNbinsX(),0,250);
    h->GetXaxis()->SetTitle("Gen Met [GeV]");
    h->GetYaxis()->SetTitle("Normalization Factor");
    
    tGenVsReco_Factor.setCellContent(i+1, 0,s->c_str());
    for(int bin=0; bin<p->GetNbinsX()+2; bin++){

      A = p->Integral(     0,            bin,binY+1,p->GetNbinsY()+1);  
      B = p->Integral(bin+1,p->GetNbinsX()+1,binY+1,p->GetNbinsY()+1); 
      
      double factor = (A+B)/B;
      
      if(B>0){h->SetBinContent(bin,factor);}
      else   {h->SetBinContent(bin,0);}
      cout << "=> " << s << " bin=" << bin << " factor=" << factor << endl;
      if(!done1p25 && factor>1.25){
	if(bin>1){tGenVsReco_Factor.setCellContent(i+1, 1,h->GetBinLowEdge(bin-1));} 
	else     {tGenVsReco_Factor.setCellContent(i+1, 1,0);}
	done1p25 = true;
      } 
      if(!done1p5 && factor>1.5){
	if(bin>1){tGenVsReco_Factor.setCellContent(i+1, 2,h->GetBinLowEdge(bin-1));} 
	else     {tGenVsReco_Factor.setCellContent(i+1, 2,0);}
	done1p5 = true;
      } 
      if(!done2p0 && factor>2.0){
	if(bin>1){tGenVsReco_Factor.setCellContent(i+1, 3,h->GetBinLowEdge(bin-1));} 
	else     {tGenVsReco_Factor.setCellContent(i+1, 3,0);}
	done2p0 = true;
      } 
      if(!done3p0 && factor>3.0){
	if(bin>1){tGenVsReco_Factor.setCellContent(i+1, 4,h->GetBinLowEdge(bin-1));} 
	else     {tGenVsReco_Factor.setCellContent(i+1, 4,0);}
	done3p0 = true;
      }
      
    }
    
    h->Draw();
    verLine.Draw();
    canv->SaveAs(Form("%s.pdf",h->GetName()));
    
    delete h;
    
  }
  
  canv->SetLogz(true); 
  TH2D *hQCDIncAll = mPlots.getMerged("MC_QCDIncAll_GenVsReco_met",samples_qcdinc);
  hQCDIncAll->Draw("colz");
  horLine.Draw();
  verLine.Draw();
  canv->SaveAs("MC_QCDIncAll_GenVsReco_met.pdf");
  
  double A   = hQCDIncAll->Integral(     0,                     binX,binY+1,hQCDIncAll->GetNbinsY()+1);  
  double B   = hQCDIncAll->Integral(binX+1,hQCDIncAll->GetNbinsX()+1,binY+1,hQCDIncAll->GetNbinsY()+1);      
  double C   = hQCDIncAll->Integral(     0,                     binX,     0,                     binY);
  double D   = hQCDIncAll->Integral(binX+1,hQCDIncAll->GetNbinsX()+1,     0,                     binY);  
  double Tot = hQCDIncAll->Integral(     0,hQCDIncAll->GetNbinsX()+1,     0,hQCDIncAll->GetNbinsY()+1);  
    
  tGenVsReco_met_Areas.setCellContent(13, 0,"Total");
  tGenVsReco_met_Areas.setCellContent(13, 1,A/Tot);
  tGenVsReco_met_Areas.setCellContent(13, 2,B/Tot);
  tGenVsReco_met_Areas.setCellContent(13, 3,C/Tot);
  tGenVsReco_met_Areas.setCellContent(13, 4,D/Tot);
  tGenVsReco_met_Areas.setCellContent(13, 5,(A+B)/B);
  
  tGenVsReco_met_Areas.saveAs("tGenVsReco_met_Areas.tex");
  tGenVsReco_Factor   .saveAs("tGenVsReco_Factor.tex");
  
  delete hQCDIncAll;
  delete canv;
  
}

double getIntegralFullRange(TH1F* plot){return plot->Integral(0,plot->GetNbinsX()+1);}

double getIntegralFullRange(TH1D* plot){return plot->Integral(0,plot->GetNbinsX()+1);}

ICLatexTabular get_tGenVsReco_met_Areas(){
  
  ICLatexTabular tGenVsReco_met_Areas(14,6);
  tGenVsReco_met_Areas.setTabularPrecision(".6");
  
  tGenVsReco_met_Areas.setTabularColumnDecoration("|");
  tGenVsReco_met_Areas.setColumnDecorationAfter  (0,"||");
  tGenVsReco_met_Areas.setColumnDecorationAfter  (4,"||");
  
  tGenVsReco_met_Areas.setRowDecorationBefore( 0,"\\hline");
  tGenVsReco_met_Areas.setRowDecorationBefore( 1,"\\hline \\hline");
  tGenVsReco_met_Areas.setRowDecorationAfter (12,"\\hline \\hline");
  tGenVsReco_met_Areas.setRowDecorationAfter (13,"\\hline");
  
  tGenVsReco_met_Areas.setCellContent(0, 0,"Sample");
  tGenVsReco_met_Areas.setCellContent(0, 1,"A");
  tGenVsReco_met_Areas.setCellContent(0, 2,"B");
  tGenVsReco_met_Areas.setCellContent(0, 3,"C");
  tGenVsReco_met_Areas.setCellContent(0, 4,"D");
  tGenVsReco_met_Areas.setCellContent(0, 5,"Factor");
  
  for(int i=1; i<13; i++){tGenVsReco_met_Areas.setCellPrecision(i,5,".3");}
  
  return tGenVsReco_met_Areas;
}

ICLatexTabular get_tGenVsReco_Factor(){
  
  ICLatexTabular tGenVsReco_Factor(14,5);
  tGenVsReco_Factor.setTabularPrecision(".1");
  
  tGenVsReco_Factor.setTabularColumnDecoration("|");
  tGenVsReco_Factor.setColumnDecorationAfter  (0,"||");
  
  tGenVsReco_Factor.setRowDecorationBefore( 0,"\\hline");
  tGenVsReco_Factor.setRowDecorationBefore( 1,"\\hline \\hline");
  tGenVsReco_Factor.setRowDecorationAfter (12,"\\hline \\hline");
  tGenVsReco_Factor.setRowDecorationAfter (13,"\\hline");
  
  tGenVsReco_Factor.setCellContent(0, 0,"Norm. Factor");
  tGenVsReco_Factor.setCellContent(0, 1,"1.25");
  tGenVsReco_Factor.setCellContent(0, 2,"1.5");
  tGenVsReco_Factor.setCellContent(0, 3,"2");
  tGenVsReco_Factor.setCellContent(0, 4,"3");
  
  return tGenVsReco_Factor;
}