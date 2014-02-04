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
#include "TCanvas.h"
#include "TString.h"

// Standard libraries includes
#include <iostream>
#include <string>
#include <map>

using namespace std;

double getIntegralFullRange(TH1F* plot);
double getIntegralFullRange(TH1D* plot);

ICLatexTabular get_tabXSec();
ICLatexTabular get_tQCDCompare_YieldAbsolute();
ICLatexTabular get_tQCDCompare_YieldTrigWgt();
ICLatexTabular get_tQCDCompare_YieldXsecWgt();

ICLatexTabular get_tQCDInc_YieldAbsolute();
ICLatexTabular get_tQCDInc_YieldTrigWgt();
ICLatexTabular get_tQCDInc_YieldXsecWgt();

ICLatexTabular get_tMCSummary_YieldAbsolute();
ICLatexTabular get_tMCSummary_YieldXsecWgt();
ICLatexTabular get_tQCDSummary_YieldWeighted();

int main(int argc, char *argv[]){

  ICStyle myStyle;
  myStyle.setTDRStyle();
  
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

  sampleID.push_back("Data_MET-2012A-13Jul2012-v1");
  sampleID.push_back("Data_MET-2012A-06Aug2012-v1");
  sampleID.push_back("Data_MET-2012B-13Jul2012-v1");
  sampleID.push_back("Data_MET-2012C-24Aug2012-v1");
  sampleID.push_back("Data_MET-2012C-11Dec2012-v1");
  sampleID.push_back("Data_MET-2012C-PromptReco-v2");
  sampleID.push_back("Data_MET-2012D-PromptReco-v1");

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
  
  sampleID.push_back("MC_QCD-Pt-80to120_VBF-MET40");
  sampleID.push_back("MC_QCD-Pt-120to170_VBF-MET40");
  sampleID.push_back("MC_QCD-Pt-170to300_VBF-MET40");
  sampleID.push_back("MC_QCD-Pt-300to470_VBF-MET40");
  sampleID.push_back("MC_QCD-Pt-470to600_VBF-MET40");
  
  // TT
  sampleID.push_back("MC_TTJets");

  //powheg samples
  sampleID.push_back("MC_TT-v1");
  sampleID.push_back("MC_TT-v2");

  //
  sampleID.push_back("MC_T-tW");
  sampleID.push_back("MC_Tbar-tW");
  sampleID.push_back("MC_SingleT-s-powheg-tauola");
  sampleID.push_back("MC_SingleTBar-s-powheg-tauola");
  sampleID.push_back("MC_SingleT-t-powheg-tauola");
  sampleID.push_back("MC_SingleTBar-t-powheg-tauola");
  sampleID.push_back("MC_WW-pythia6-tauola");       
  sampleID.push_back("MC_WZ-pythia6-tauola");       
  sampleID.push_back("MC_ZZ-pythia6-tauola");        
  sampleID.push_back("MC_W1JetsToLNu_enu");         
  sampleID.push_back("MC_W2JetsToLNu_enu");         
  sampleID.push_back("MC_W3JetsToLNu_enu");         
  sampleID.push_back("MC_W4JetsToLNu_enu");       
  sampleID.push_back("MC_WJetsToLNu-v1_enu");       
  sampleID.push_back("MC_WJetsToLNu-v2_enu");        
  sampleID.push_back("MC_W1JetsToLNu_munu");        
  sampleID.push_back("MC_W2JetsToLNu_munu");        
  sampleID.push_back("MC_W3JetsToLNu_munu");        
  sampleID.push_back("MC_W4JetsToLNu_munu");      
  sampleID.push_back("MC_WJetsToLNu-v1_munu");      
  sampleID.push_back("MC_WJetsToLNu-v2_munu");       
  sampleID.push_back("MC_W1JetsToLNu_taunu");       
  sampleID.push_back("MC_W2JetsToLNu_taunu");       
  sampleID.push_back("MC_W3JetsToLNu_taunu");       
  sampleID.push_back("MC_W4JetsToLNu_taunu");     
  sampleID.push_back("MC_WJetsToLNu-v1_taunu");     
  sampleID.push_back("MC_WJetsToLNu-v2_taunu");    
  sampleID.push_back("MC_DYJetsToLL");             
  sampleID.push_back("MC_DY1JetsToLL");             
  sampleID.push_back("MC_DY2JetsToLL");             
  sampleID.push_back("MC_DY3JetsToLL");             
  sampleID.push_back("MC_DY4JetsToLL");  
  sampleID.push_back("MC_ZJetsToNuNu_100_HT_200");  
  sampleID.push_back("MC_ZJetsToNuNu_200_HT_400");  
  sampleID.push_back("MC_ZJetsToNuNu_400_HT_inf");   
  sampleID.push_back("MC_ZJetsToNuNu_50_HT_100");
  sampleID.push_back("MC_GJets-HT-200To400-madgraph");
  sampleID.push_back("MC_GJets-HT-400ToInf-madgraph");
  sampleID.push_back("MC_VBF_HToZZTo4Nu_M-120");    
  sampleID.push_back("MC_EWK-Z2j");            
  sampleID.push_back("MC_EWK-Z2jiglep");             
  sampleID.push_back("MC_EWK-W2jminus_enu");         
  sampleID.push_back("MC_EWK-W2jplus_enu");          
  sampleID.push_back("MC_EWK-W2jminus_munu");        
  sampleID.push_back("MC_EWK-W2jplus_munu");         
  sampleID.push_back("MC_EWK-W2jminus_taunu");       
  sampleID.push_back("MC_EWK-W2jplus_taunu");        
  sampleID.push_back("MC_WGamma");                   
  
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
  
  vector<string> samples_QCDVbfCompare;
  samples_QCDVbfCompare.push_back("MC_QCD-Pt-80to120_VBF-MET40");
  samples_QCDVbfCompare.push_back("MC_QCD-Pt-120to170_VBF-MET40");
  samples_QCDVbfCompare.push_back("MC_QCD-Pt-170to300_VBF-MET40");
  samples_QCDVbfCompare.push_back("MC_QCD-Pt-300to470_VBF-MET40");
  samples_QCDVbfCompare.push_back("MC_QCD-Pt-470to600_VBF-MET40");

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
  
  // QCD VBF + other
  vector<string> samples_qcdvbfextra;
  samples_qcdvbfextra.push_back("MC_QCD-Pt-30to50-pythia6");
  samples_qcdvbfextra.push_back("MC_QCD-Pt-50to80-pythia6");    
  samples_qcdvbfextra.push_back("MC_QCD-Pt-80to120_VBF-MET40");   
  samples_qcdvbfextra.push_back("MC_QCD-Pt-120to170_VBF-MET40");  
  samples_qcdvbfextra.push_back("MC_QCD-Pt-170to300_VBF-MET40"); 
  samples_qcdvbfextra.push_back("MC_QCD-Pt-300to470_VBF-MET40"); 
  samples_qcdvbfextra.push_back("MC_QCD-Pt-470to600_VBF-MET40"); 
  samples_qcdvbfextra.push_back("MC_QCD-Pt-600to800-pythia6"); 
  samples_qcdvbfextra.push_back("MC_QCD-Pt-800to1000-pythia6"); 
  samples_qcdvbfextra.push_back("MC_QCD-Pt-1000to1400-pythia6");
  samples_qcdvbfextra.push_back("MC_QCD-Pt-1400to1800-pythia6");
  samples_qcdvbfextra.push_back("MC_QCD-Pt-1800-pythia6");    

  // Data
  vector<string> samples_data;
  samples_data.push_back("Data_MET-2012A-13Jul2012-v1");
  samples_data.push_back("Data_MET-2012A-06Aug2012-v1");
  samples_data.push_back("Data_MET-2012B-13Jul2012-v1");
  samples_data.push_back("Data_MET-2012C-24Aug2012-v1");
  samples_data.push_back("Data_MET-2012C-11Dec2012-v1");
  samples_data.push_back("Data_MET-2012C-PromptReco-v2");
  samples_data.push_back("Data_MET-2012D-PromptReco-v1");

  // Samples VV
  vector<string> samples_vv;
  samples_vv.push_back("MC_WW-pythia6-tauola");
  samples_vv.push_back("MC_WZ-pythia6-tauola");
  samples_vv.push_back("MC_ZZ-pythia6-tauola");
  samples_vv.push_back("MC_WGamma");
  
  // Samples W+jets (Correct)
  vector<string> samples_wjets;     
  samples_wjets.push_back("MC_WJetsToLNu-v1_enu");  
  samples_wjets.push_back("MC_WJetsToLNu-v2_enu");  
  samples_wjets.push_back("MC_W1JetsToLNu_enu");    
  samples_wjets.push_back("MC_W2JetsToLNu_enu");    
  samples_wjets.push_back("MC_W3JetsToLNu_enu");    
  samples_wjets.push_back("MC_W4JetsToLNu_enu");    
  samples_wjets.push_back("MC_WJetsToLNu-v1_munu"); 
  samples_wjets.push_back("MC_WJetsToLNu-v2_munu"); 
  samples_wjets.push_back("MC_W1JetsToLNu_munu");   
  samples_wjets.push_back("MC_W2JetsToLNu_munu");   
  samples_wjets.push_back("MC_W3JetsToLNu_munu");   
  samples_wjets.push_back("MC_W4JetsToLNu_munu");   
  samples_wjets.push_back("MC_W1JetsToLNu_taunu");  
  samples_wjets.push_back("MC_W2JetsToLNu_taunu");  
  samples_wjets.push_back("MC_W3JetsToLNu_taunu");  
  samples_wjets.push_back("MC_W4JetsToLNu_taunu");  
  samples_wjets.push_back("MC_WJetsToLNu-v1_taunu");
  samples_wjets.push_back("MC_WJetsToLNu-v2_taunu");  
  
  // Samples top (Correct)
  vector<string> samples_ttbar;
  samples_ttbar.push_back("MC_TTJets");
  samples_ttbar.push_back("MC_T-tW");
  samples_ttbar.push_back("MC_Tbar-tW");
  samples_ttbar.push_back("MC_SingleT-s-powheg-tauola");
  samples_ttbar.push_back("MC_SingleTBar-s-powheg-tauola");
  samples_ttbar.push_back("MC_SingleT-t-powheg-tauola");
  samples_ttbar.push_back("MC_SingleTBar-t-powheg-tauola");  
  
  // Samples G+Jets (Correct)
  vector<string> samples_gjets;
  samples_gjets.push_back("MC_GJets-HT-200To400-madgraph");
  samples_gjets.push_back("MC_GJets-HT-400ToInf-madgraph");
  
  // Samples EWK
  vector<string> samples_ewk;
  samples_ewk.push_back("MC_EWK-Z2j");
  samples_ewk.push_back("MC_EWK-Z2jiglep");
  samples_ewk.push_back("MC_EWK-W2jminus_enu");
  samples_ewk.push_back("MC_EWK-W2jplus_enu");
  samples_ewk.push_back("MC_EWK-W2jminus_munu");
  samples_ewk.push_back("MC_EWK-W2jplus_munu");
  samples_ewk.push_back("MC_EWK-W2jminus_taunu");
  samples_ewk.push_back("MC_EWK-W2jplus_taunu");

  // Samples ZJets
  vector<string> samples_zjets;
  samples_zjets.push_back("MC_ZJetsToNuNu_100_HT_200");
  samples_zjets.push_back("MC_ZJetsToNuNu_200_HT_400");
  samples_zjets.push_back("MC_ZJetsToNuNu_400_HT_inf");
  samples_zjets.push_back("MC_ZJetsToNuNu_50_HT_100");
  
  // Samples DY
  vector<string> samples_dy;
  samples_dy.push_back("MC_DYJetsToLL");
  samples_dy.push_back("MC_DY1JetsToLL");
  samples_dy.push_back("MC_DY2JetsToLL");
  samples_dy.push_back("MC_DY3JetsToLL");
  samples_dy.push_back("MC_DY4JetsToLL");
  
  //_________________________________________________________________________________________________
  // Cuts and histograms to print out to PDF
  //_________________________________________________________________________________________________
  vector<string> cuts;
  cuts.push_back("HLTMetClean");
  cuts.push_back("JetPair");  
  cuts.push_back("DEta");
  cuts.push_back("MET");
  cuts.push_back("TightMjj");
  cuts.push_back("CJVpass");
  cuts.push_back("DPhiSIGNAL_CJVpass");

  vector<string> hists;  
  hists.push_back("jpt_1");
  hists.push_back("jpt_2");
  hists.push_back("jeta_1");
  hists.push_back("jeta_2");
  hists.push_back("met");
  hists.push_back("mjj");
  hists.push_back("dphijj");
  
  for(unsigned c=0; c<cuts.size(); c++){
    for(unsigned h=0; h<hists.size(); h++){
      
      TH1F *hInc,*hVBF,*hData;
      TCanvas *canv = new TCanvas();

      MapString_ICH1F mPlots  = MapString_ICH1F(files,Form("%s/%s",cuts[c].c_str(),hists[h].c_str()));
      mPlots.Scale(wgt);  // removed since already included
      
      hData = mPlots.getMerged(Form("Data_%s_%s",  cuts[c].c_str(),hists[h].c_str()),samples_data);
      hInc  = mPlots.getMerged(Form("QCDInc_%s_%s",cuts[c].c_str(),hists[h].c_str()),samples_QCDIncCompare);
      hVBF  = mPlots.getMerged(Form("QCDVBF_%s_%s",cuts[c].c_str(),hists[h].c_str()),samples_QCDVbfCompare);

      if(hData->Integral()!=0){hData->Scale(1/getIntegralFullRange(hData));}      
      if(hInc->Integral()!=0) {hInc ->Scale(1/getIntegralFullRange(hInc));}
      if(hVBF->Integral()!=0) {hVBF ->Scale(1/getIntegralFullRange(hVBF));}      
      
      if     (cuts[c]=="HLTMetClean"        && hists[h]=="jpt_1") {int r= 5; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="HLTMetClean"        && hists[h]=="jpt_2") {int r= 5; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="HLTMetClean"        && hists[h]=="jeta_1"){int r= 2; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="HLTMetClean"        && hists[h]=="jeta_2"){int r= 2; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="HLTMetClean"        && hists[h]=="met")   {int r= 4; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,300);}
      else if(cuts[c]=="HLTMetClean"        && hists[h]=="mjj")   {int r=25; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,2500);}
      else if(cuts[c]=="JetPair"            && hists[h]=="jpt_1") {int r= 5; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="JetPair"            && hists[h]=="jpt_2") {int r= 5; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="JetPair"            && hists[h]=="jeta_1"){int r= 2; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="JetPair"            && hists[h]=="jeta_2"){int r= 2; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="JetPair"            && hists[h]=="met")   {int r= 4; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,300);}
      else if(cuts[c]=="JetPair"            && hists[h]=="mjj")   {int r=25; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,2500);}
      else if(cuts[c]=="DEta"               && hists[h]=="jpt_1") {int r= 5; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="DEta"               && hists[h]=="jpt_2") {int r= 5; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="DEta"               && hists[h]=="jeta_1"){int r= 2; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="DEta"               && hists[h]=="jeta_2"){int r= 2; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="DEta"               && hists[h]=="met")   {int r= 4; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,300);}
      else if(cuts[c]=="DEta"               && hists[h]=="mjj")   {int r=25; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,2500);}     
      else if(cuts[c]=="MET"                && hists[h]=="jpt_1") {int r=20; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="MET"                && hists[h]=="jpt_2") {int r=20; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="MET"                && hists[h]=="jeta_1"){int r= 4; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="MET"                && hists[h]=="jeta_2"){int r= 4; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="MET"                && hists[h]=="met")   {int r= 8; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,300);}
      else if(cuts[c]=="MET"                && hists[h]=="mjj")   {int r=50; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,2500);}     
      else if(cuts[c]=="TightMjj"           && hists[h]=="jpt_1") {int r=20; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="TightMjj"           && hists[h]=="jpt_2") {int r=20; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="TightMjj"           && hists[h]=="jeta_1"){int r= 4; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="TightMjj"           && hists[h]=="jeta_2"){int r= 4; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="TightMjj"           && hists[h]=="met")   {int r= 8; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,300);}
      else if(cuts[c]=="TightMjj"           && hists[h]=="mjj")   {int r=50; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,2500);}  
      else if(cuts[c]=="TightMjj"           && hists[h]=="dphijj"){int r= 4; hInc->Rebin(r);hVBF->Rebin(r);hData->Rebin(r);} 
      else if(cuts[c]=="CJVpass"            && hists[h]=="jpt_1") {int r=20; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="CJVpass"            && hists[h]=="jpt_2") {int r=20; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="CJVpass"            && hists[h]=="jeta_1"){int r= 4; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="CJVpass"            && hists[h]=="jeta_2"){int r= 4; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="CJVpass"            && hists[h]=="met")   {int r= 8; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,300);}
      else if(cuts[c]=="CJVpass"            && hists[h]=="mjj")   {int r=50; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,2500);}     
      else if(cuts[c]=="CJVpass"            && hists[h]=="dphijj"){int r= 4; hInc->Rebin(r);hVBF->Rebin(r);hData->Rebin(r);} 
      else if(cuts[c]=="DPhiSIGNAL_CJVpass" && hists[h]=="jpt_1") {int r=20; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="DPhiSIGNAL_CJVpass" && hists[h]=="jpt_2") {int r=20; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="DPhiSIGNAL_CJVpass" && hists[h]=="jeta_1"){int r= 4; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="DPhiSIGNAL_CJVpass" && hists[h]=="jeta_2"){int r= 4; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="DPhiSIGNAL_CJVpass" && hists[h]=="met")   {int r= 8; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,300);}
      else if(cuts[c]=="DPhiSIGNAL_CJVpass" && hists[h]=="mjj")   {int r=50; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,2500);} 
      else if(cuts[c]=="DPhiSIGNAL_CJVpass" && hists[h]=="mjj")   {int r=50; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,2500);}       

      hData->SetLineColor(kBlack);
      hVBF ->SetLineColor(kRed);
      hInc ->SetLineColor(kBlue);
      
      if(hists[h]=="dphijj"){
	canv->SetLogy(true);

        hData->SetMarkerStyle(20);
	hData->SetMarkerSize(1);
	
	hVBF->SetFillColor(kRed);
	hVBF->GetXaxis()->SetTitle("#Delta#phi");
	hVBF->GetXaxis()->SetTitle("Normalized to 1");
	
        hVBF ->Draw("HIST");
	hData->Draw("sameP0E1");
        canv->SaveAs(Form("DataVsQCDVBF_%s_%s.pdf",cuts[c].c_str(),hists[h].c_str()));
	
      }
      
      else{canv->SetLogy(false);}
      
      hInc->Draw("");
      hVBF->Draw("same");
      canv->SaveAs(Form("%s_%s.pdf",cuts[c].c_str(),hists[h].c_str()));
      
      delete hData;
      delete hInc;
      delete hVBF;
      delete canv;
    } 
  }
  
  //_________________________________________________________________________________________________
  // Filling table: Cross sections
  //_________________________________________________________________________________________________
//   ICLatexTabular tabXSec = get_tabXSec();
// 
//   for(unsigned i=0; i<sampleID.size(); i++){
//     
//     string* s = &(sampleID[i]);
//     
//     tabXSec.setCellContent(int(i+1),0,Form("\\verb|%s|",(*s).c_str()));//samples[i]);  
//     tabXSec.setCellContent(int(i+1),1,xsec[(*s)]);//xsec[(*s)]);
//     tabXSec.setCellContent(int(i+1),2,wgt [(*s)]);//wgt [(*s)]);
//   }
// 
//   tabXSec.saveAs("table_xSec.tex");
//   tabXSec.print();
//          
  //_____________________________________________________
  ICLatexTabular tQCDCompare_YieldAbsolute = get_tQCDCompare_YieldAbsolute(); // Initialization of absolute event yields table 
  ICLatexTabular tQCDCompare_YieldTrigWgt  = get_tQCDCompare_YieldTrigWgt();  // Initialization of trigger weighted eventd
  ICLatexTabular tQCDCompare_YieldXsecWgt  = get_tQCDCompare_YieldXsecWgt();  // Initialization of xsec weighted
 
  ICLatexTabular tQCDInc_YieldAbsolute     = get_tQCDInc_YieldAbsolute();
  ICLatexTabular tQCDInc_YieldTrigWgt      = get_tQCDInc_YieldTrigWgt();      // Initialization of merged table
  ICLatexTabular tQCDInc_YieldXsecWgt      = get_tQCDInc_YieldXsecWgt();  // Initialization of xsec weighted

  ICLatexTabular tMCSummary_YieldAbsolute  = get_tMCSummary_YieldAbsolute(); // Initialization of merged table  
  ICLatexTabular tMCSummary_YieldXsecWgt   = get_tMCSummary_YieldXsecWgt();  // Initialization of merged table
  
  ICLatexTabular tQCDSummary_YieldWeighted = get_tQCDSummary_YieldWeighted(); 
  
  //_________________________________________    
  for(unsigned i=0; i<cuts.size(); i++){
    
    MapString_ICH1F mPlots = MapString_ICH1F(files,Form("%s/n_vtx",cuts[i].c_str()));

    // QCD Sample Compare: Filling table absolute counts 
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 0,cuts[i]);
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 1,mPlots["MC_QCD-Pt-80to120-pythia6"]   ->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 2,mPlots["MC_QCD-Pt-80to120_VBF-MET40"] ->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 3,mPlots["MC_QCD-Pt-120to170-pythia6"]  ->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 4,mPlots["MC_QCD-Pt-120to170_VBF-MET40"]->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 5,mPlots["MC_QCD-Pt-170to300-pythia6"]  ->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 6,mPlots["MC_QCD-Pt-170to300_VBF-MET40"]->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 7,mPlots["MC_QCD-Pt-300to470-pythia6"]  ->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 8,mPlots["MC_QCD-Pt-300to470_VBF-MET40"]->GetEntries());    
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 9,mPlots["MC_QCD-Pt-470to600-pythia6"]  ->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2,10,mPlots["MC_QCD-Pt-470to600_VBF-MET40"]->GetEntries());

    // QCD Sample Compare: Filling table weighted events (trigger, pu)
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 0,cuts[i]);
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 1,getIntegralFullRange(mPlots["MC_QCD-Pt-80to120-pythia6"]));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 2,getIntegralFullRange(mPlots["MC_QCD-Pt-80to120_VBF-MET40"]));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 3,getIntegralFullRange(mPlots["MC_QCD-Pt-120to170-pythia6"]));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 4,getIntegralFullRange(mPlots["MC_QCD-Pt-120to170_VBF-MET40"]));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 5,getIntegralFullRange(mPlots["MC_QCD-Pt-170to300-pythia6"]));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 6,getIntegralFullRange(mPlots["MC_QCD-Pt-170to300_VBF-MET40"]));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 7,getIntegralFullRange(mPlots["MC_QCD-Pt-300to470-pythia6"]));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 8,getIntegralFullRange(mPlots["MC_QCD-Pt-300to470_VBF-MET40"]));    
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 9,getIntegralFullRange(mPlots["MC_QCD-Pt-470to600-pythia6"]));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2,10,getIntegralFullRange(mPlots["MC_QCD-Pt-470to600_VBF-MET40"]));    
  
    
    // QCD Inclusive: Filling table absolute counts 
    tQCDInc_YieldAbsolute.setCellContent(i+1, 0,cuts[i]);
    tQCDInc_YieldAbsolute.setCellContent(i+1, 1,mPlots["MC_QCD-Pt-30to50-pythia6"]    ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 2,mPlots["MC_QCD-Pt-50to80-pythia6"]    ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 3,mPlots["MC_QCD-Pt-80to120-pythia6"]   ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 4,mPlots["MC_QCD-Pt-120to170-pythia6"]  ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 5,mPlots["MC_QCD-Pt-170to300-pythia6"]  ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 6,mPlots["MC_QCD-Pt-300to470-pythia6"]  ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 7,mPlots["MC_QCD-Pt-470to600-pythia6"]  ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 8,mPlots["MC_QCD-Pt-600to800-pythia6"]  ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 9,mPlots["MC_QCD-Pt-800to1000-pythia6"] ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1,10,mPlots["MC_QCD-Pt-1000to1400-pythia6"]->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1,11,mPlots["MC_QCD-Pt-1400to1800-pythia6"]->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1,12,mPlots["MC_QCD-Pt-1800-pythia6"]      ->GetEntries());
    
    // QCD Inclusive: Filling table weighted events (trigger, pu) for All QCD Inclusive samples
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 0,cuts[i]);
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 1,getIntegralFullRange(mPlots["MC_QCD-Pt-30to50-pythia6"]));
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 2,getIntegralFullRange(mPlots["MC_QCD-Pt-50to80-pythia6"]));
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 3,getIntegralFullRange(mPlots["MC_QCD-Pt-80to120-pythia6"]));
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 4,getIntegralFullRange(mPlots["MC_QCD-Pt-120to170-pythia6"]));
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 5,getIntegralFullRange(mPlots["MC_QCD-Pt-170to300-pythia6"]));
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 6,getIntegralFullRange(mPlots["MC_QCD-Pt-300to470-pythia6"]));    
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 7,getIntegralFullRange(mPlots["MC_QCD-Pt-470to600-pythia6"]));
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 8,getIntegralFullRange(mPlots["MC_QCD-Pt-600to800-pythia6"]));
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 9,getIntegralFullRange(mPlots["MC_QCD-Pt-800to1000-pythia6"]));
    tQCDInc_YieldTrigWgt.setCellContent(i+1,10,getIntegralFullRange(mPlots["MC_QCD-Pt-1000to1400-pythia6"]));
    tQCDInc_YieldTrigWgt.setCellContent(i+1,11,getIntegralFullRange(mPlots["MC_QCD-Pt-1400to1800-pythia6"]));
    tQCDInc_YieldTrigWgt.setCellContent(i+1,12,getIntegralFullRange(mPlots["MC_QCD-Pt-1800-pythia6"]));

    // Merging samples and calculating integral    
    TH1F *hData   = mPlots.getMerged(Form("Data_%s_n_vtx",  cuts[i].c_str()),samples_data);
    TH1F *hQCDInc = mPlots.getMerged(Form("QCDInc_%s_n_vtx",cuts[i].c_str()),samples_QCDIncCompare);
    TH1F *hQCDVBF = mPlots.getMerged(Form("QCDVBF_%s_n_vtx",cuts[i].c_str()),samples_QCDVbfCompare);
    TH1F *hTTbar  = mPlots.getMerged(Form("TTBar_%s_n_vtx", cuts[i].c_str()),samples_ttbar);
    TH1F *hWjets  = mPlots.getMerged(Form("Wjets_%s_n_vtx", cuts[i].c_str()),samples_wjets);
    TH1F *hVV     = mPlots.getMerged(Form("VV_%s_n_vtx",    cuts[i].c_str()),samples_vv);
    TH1F *hGjets  = mPlots.getMerged(Form("Gjets_%s_n_vtx", cuts[i].c_str()),samples_gjets);
    TH1F *hEWK    = mPlots.getMerged(Form("EWK_%s_n_vtx",   cuts[i].c_str()),samples_ewk);
    TH1F *hZjets  = mPlots.getMerged(Form("Zjets_%s_n_vtx", cuts[i].c_str()),samples_zjets);
    TH1F *hDY     = mPlots.getMerged(Form("DY_%s_n_vtx",    cuts[i].c_str()),samples_dy);
    
    TH1F *hQCDIncAll = mPlots.getMerged(Form("QCDIncAll_%s_n_vtx",cuts[i].c_str()),samples_qcdinc);
    TH1F *hQCDVBFAll = mPlots.getMerged(Form("QCDVBFAll_%s_n_vtx",cuts[i].c_str()),samples_qcdvbfextra);
    
    tMCSummary_YieldAbsolute.setCellContent(i+1, 0,cuts[i]);
    tMCSummary_YieldAbsolute.setCellContent(i+1, 1,hData->GetEntries());
    tMCSummary_YieldAbsolute.setCellContent(i+1, 2,hQCDIncAll->GetEntries());
    tMCSummary_YieldAbsolute.setCellContent(i+1, 3,hQCDVBFAll->GetEntries());
    tMCSummary_YieldAbsolute.setCellContent(i+1, 4,hTTbar->GetEntries());
    tMCSummary_YieldAbsolute.setCellContent(i+1, 5,hWjets->GetEntries());
    tMCSummary_YieldAbsolute.setCellContent(i+1, 6,hVV->GetEntries());
    tMCSummary_YieldAbsolute.setCellContent(i+1, 7,hGjets->GetEntries());
    tMCSummary_YieldAbsolute.setCellContent(i+1, 8,hEWK->GetEntries());
    tMCSummary_YieldAbsolute.setCellContent(i+1, 9,hZjets->GetEntries());
    tMCSummary_YieldAbsolute.setCellContent(i+1,10,hDY->GetEntries());
    
    delete hData;
    delete hQCDInc;
    delete hQCDVBF;
    delete hTTbar;
    delete hWjets;
    delete hVV;
    delete hGjets;
    delete hEWK;
    delete hZjets;
    delete hDY;
    delete hQCDIncAll;
    delete hQCDVBFAll;

    
    // Putting in cross section normalization weights
    mPlots.Scale(wgt);

    // Filling table weighted events (trigger, pu and xsec)
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 0,cuts[i]);
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 1,getIntegralFullRange(mPlots["MC_QCD-Pt-80to120-pythia6"]));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 2,getIntegralFullRange(mPlots["MC_QCD-Pt-80to120_VBF-MET40"]));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 3,getIntegralFullRange(mPlots["MC_QCD-Pt-120to170-pythia6"]));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 4,getIntegralFullRange(mPlots["MC_QCD-Pt-120to170_VBF-MET40"]));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 5,getIntegralFullRange(mPlots["MC_QCD-Pt-170to300-pythia6"]));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 6,getIntegralFullRange(mPlots["MC_QCD-Pt-170to300_VBF-MET40"]));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 7,getIntegralFullRange(mPlots["MC_QCD-Pt-300to470-pythia6"]));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 8,getIntegralFullRange(mPlots["MC_QCD-Pt-300to470_VBF-MET40"]));    
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 9,getIntegralFullRange(mPlots["MC_QCD-Pt-470to600-pythia6"]));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2,10,getIntegralFullRange(mPlots["MC_QCD-Pt-470to600_VBF-MET40"]));    
  
    // QCD Inclusive: Filling table weighted events (trigger, pu and xsec)
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 0,cuts[i]);
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 1,getIntegralFullRange(mPlots["MC_QCD-Pt-30to50-pythia6"]));
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 2,getIntegralFullRange(mPlots["MC_QCD-Pt-50to80-pythia6"]));
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 3,getIntegralFullRange(mPlots["MC_QCD-Pt-80to120-pythia6"]));
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 4,getIntegralFullRange(mPlots["MC_QCD-Pt-120to170-pythia6"]));
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 5,getIntegralFullRange(mPlots["MC_QCD-Pt-170to300-pythia6"]));
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 6,getIntegralFullRange(mPlots["MC_QCD-Pt-300to470-pythia6"]));    
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 7,getIntegralFullRange(mPlots["MC_QCD-Pt-470to600-pythia6"]));
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 8,getIntegralFullRange(mPlots["MC_QCD-Pt-600to800-pythia6"]));
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 9,getIntegralFullRange(mPlots["MC_QCD-Pt-800to1000-pythia6"]));
    tQCDInc_YieldXsecWgt.setCellContent(i+1,10,getIntegralFullRange(mPlots["MC_QCD-Pt-1000to1400-pythia6"]));
    tQCDInc_YieldXsecWgt.setCellContent(i+1,11,getIntegralFullRange(mPlots["MC_QCD-Pt-1400to1800-pythia6"]));
    tQCDInc_YieldXsecWgt.setCellContent(i+1,12,getIntegralFullRange(mPlots["MC_QCD-Pt-1800-pythia6"]));    

    // Merging samples and calculating integral    
    hData   = mPlots.getMerged(Form("Data_%s_n_vtx",  cuts[i].c_str()),samples_data);
    hQCDInc = mPlots.getMerged(Form("QCDInc_%s_n_vtx",cuts[i].c_str()),samples_QCDIncCompare);
    hQCDVBF = mPlots.getMerged(Form("QCDVBF_%s_n_vtx",cuts[i].c_str()),samples_QCDVbfCompare);
    hTTbar  = mPlots.getMerged(Form("TTBar_%s_n_vtx", cuts[i].c_str()),samples_ttbar);
    hWjets  = mPlots.getMerged(Form("Wjets_%s_n_vtx", cuts[i].c_str()),samples_wjets);
    hVV     = mPlots.getMerged(Form("VV_%s_n_vtx",    cuts[i].c_str()),samples_vv);
    hGjets  = mPlots.getMerged(Form("Gjets_%s_n_vtx", cuts[i].c_str()),samples_gjets);
    hEWK    = mPlots.getMerged(Form("EWK_%s_n_vtx",   cuts[i].c_str()),samples_ewk);
    hZjets  = mPlots.getMerged(Form("Zjets_%s_n_vtx", cuts[i].c_str()),samples_zjets);
    hDY     = mPlots.getMerged(Form("DY_%s_n_vtx",    cuts[i].c_str()),samples_dy);
    
    hQCDIncAll = mPlots.getMerged(Form("QCDIncAll_%s_n_vtx",cuts[i].c_str()),samples_qcdinc);
    hQCDVBFAll = mPlots.getMerged(Form("QCDVBFAll_%s_n_vtx",cuts[i].c_str()),samples_qcdvbfextra);
    
    tMCSummary_YieldXsecWgt.setCellContent(i+1, 0,cuts[i]);
    tMCSummary_YieldXsecWgt.setCellContent(i+1, 1,getIntegralFullRange(hData));
    tMCSummary_YieldXsecWgt.setCellContent(i+1, 2,getIntegralFullRange(hQCDIncAll));
    tMCSummary_YieldXsecWgt.setCellContent(i+1, 3,getIntegralFullRange(hQCDVBFAll));
    tMCSummary_YieldXsecWgt.setCellContent(i+1, 4,getIntegralFullRange(hTTbar));
    tMCSummary_YieldXsecWgt.setCellContent(i+1, 5,getIntegralFullRange(hWjets));
    tMCSummary_YieldXsecWgt.setCellContent(i+1, 6,getIntegralFullRange(hVV));
    tMCSummary_YieldXsecWgt.setCellContent(i+1, 7,getIntegralFullRange(hGjets));
    tMCSummary_YieldXsecWgt.setCellContent(i+1, 8,getIntegralFullRange(hEWK));
    tMCSummary_YieldXsecWgt.setCellContent(i+1, 9,getIntegralFullRange(hZjets));
    tMCSummary_YieldXsecWgt.setCellContent(i+1,10,getIntegralFullRange(hDY));
    
    double mcTotal = getIntegralFullRange(hTTbar)
                    +getIntegralFullRange(hWjets)
                    +getIntegralFullRange(hVV)
                    +getIntegralFullRange(hGjets)
                    +getIntegralFullRange(hEWK)
                    +getIntegralFullRange(hZjets)
                    +getIntegralFullRange(hDY);
    
    tQCDSummary_YieldWeighted.setCellContent(i+1, 0,cuts[i]);
    tQCDSummary_YieldWeighted.setCellContent(i+1, 1,getIntegralFullRange(hQCDIncAll));
    tQCDSummary_YieldWeighted.setCellContent(i+1, 2,getIntegralFullRange(hQCDVBFAll));
    tQCDSummary_YieldWeighted.setCellContent(i+1, 3,getIntegralFullRange(hData));
    tQCDSummary_YieldWeighted.setCellContent(i+1, 4,mcTotal);

    delete hData;
    delete hQCDInc;
    delete hQCDVBF;
    delete hTTbar;
    delete hWjets;
    delete hVV;
    delete hGjets;
    delete hEWK;
    delete hZjets;
    delete hDY;
    delete hQCDIncAll;
    delete hQCDVBFAll;
    
  }
  
  // Fixing the underscore
  tQCDCompare_YieldAbsolute.setCellContent(8, 0,"DPhi");
  tQCDCompare_YieldTrigWgt .setCellContent(8, 0,"DPhi");
  tQCDCompare_YieldXsecWgt .setCellContent(8, 0,"DPhi");
  tQCDInc_YieldAbsolute    .setCellContent(7, 0,"DPhi");
  tQCDInc_YieldTrigWgt     .setCellContent(7, 0,"DPhi");
  tQCDInc_YieldXsecWgt     .setCellContent(7, 0,"DPhi");
  tMCSummary_YieldXsecWgt  .setCellContent(7, 0,"DPhi");
  tMCSummary_YieldAbsolute .setCellContent(7, 0,"DPhi");
  tQCDSummary_YieldWeighted.setCellContent(7, 0,"DPhi");

  tQCDCompare_YieldAbsolute.saveAs("tQCDCompare_YieldAbsolute.tex");
  tQCDCompare_YieldTrigWgt .saveAs("tQCDCompare_YieldTrigWgt.tex");
  tQCDCompare_YieldXsecWgt .saveAs("tQCDCompare_YieldXsecWgt.tex");
  tQCDInc_YieldAbsolute    .saveAs("tQCDInc_YieldAbsolute.tex");
  tQCDInc_YieldTrigWgt     .saveAs("tQCDInc_YieldTrigWgt.tex");
  tQCDInc_YieldXsecWgt     .saveAs("tQCDInc_YieldXsecWgt.tex");
  tMCSummary_YieldAbsolute .saveAs("tMCSummary_YieldAbsolute.tex");
  tMCSummary_YieldXsecWgt  .saveAs("tMCSummary_YieldXsecWgt.tex");
  
  tQCDSummary_YieldWeighted.saveAs("tQCDSummary_YieldWeighted.tex");
  
}

double getIntegralFullRange(TH1F* plot){return plot->Integral(0,plot->GetNbinsX()+1);}

double getIntegralFullRange(TH1D* plot){return plot->Integral(0,plot->GetNbinsX()+1);}

//_____________________________________________________
ICLatexTabular get_tabXSec(){
  
  ICLatexTabular tabXSec(18,3);
  
  tabXSec.setCellContent(0,0,"Sample");
  tabXSec.setCellContent(0,1,"Cross Section [pb]");
  tabXSec.setCellContent(0,2,"Event Weight");
  
  tabXSec.setColumnDecorationBefore(0,"|");
  tabXSec.setColumnDecorationAfter (2,"|");
  
  tabXSec.setRowDecorationBefore( 0,"\\hline");
  tabXSec.setRowDecorationBefore( 1,"\\hline \\hline");
  tabXSec.setRowDecorationAfter (17,"\\hline");
  
  return tabXSec;
}

//_____________________________________________________
ICLatexTabular get_tQCDCompare_YieldAbsolute(){

  ICLatexTabular tQCDCompare_YieldAbsolute(9,11);
  tQCDCompare_YieldAbsolute.setTabularPrecision(".0");
  
  tQCDCompare_YieldAbsolute.setColumnDecorationBefore( 0,"|");
  tQCDCompare_YieldAbsolute.setColumnDecorationAfter ( 0,"||");
  tQCDCompare_YieldAbsolute.setColumnDecorationAfter ( 2,"||");
  tQCDCompare_YieldAbsolute.setColumnDecorationAfter ( 4,"||");
  tQCDCompare_YieldAbsolute.setColumnDecorationAfter ( 6,"||");
  tQCDCompare_YieldAbsolute.setColumnDecorationAfter ( 8,"||");
  tQCDCompare_YieldAbsolute.setColumnDecorationAfter (10,"|");
  
  tQCDCompare_YieldAbsolute.setRowDecorationBefore(0,"\\hline");
  tQCDCompare_YieldAbsolute.setRowDecorationBefore(1,"\\hline");
  tQCDCompare_YieldAbsolute.setRowDecorationBefore(2,"\\hline \\hline");
  tQCDCompare_YieldAbsolute.setRowDecorationAfter (8,"\\hline");
  
  tQCDCompare_YieldAbsolute.setCellContent(1, 0,"Sample");
  tQCDCompare_YieldAbsolute.setCellContent(0, 1, "80-120"); tQCDCompare_YieldAbsolute.setCellContent(1, 1,"Inc");
  tQCDCompare_YieldAbsolute.setCellContent(0, 2, "80-120"); tQCDCompare_YieldAbsolute.setCellContent(1, 2,"VBF");
  tQCDCompare_YieldAbsolute.setCellContent(0, 3,"120-170"); tQCDCompare_YieldAbsolute.setCellContent(1, 3,"Inc");
  tQCDCompare_YieldAbsolute.setCellContent(0, 4,"120-170"); tQCDCompare_YieldAbsolute.setCellContent(1, 4,"VBF");
  tQCDCompare_YieldAbsolute.setCellContent(0, 5,"170-300"); tQCDCompare_YieldAbsolute.setCellContent(1, 5,"Inc");
  tQCDCompare_YieldAbsolute.setCellContent(0, 6,"170-300"); tQCDCompare_YieldAbsolute.setCellContent(1, 6,"VBF");
  tQCDCompare_YieldAbsolute.setCellContent(0, 7,"300-470"); tQCDCompare_YieldAbsolute.setCellContent(1, 7,"Inc");
  tQCDCompare_YieldAbsolute.setCellContent(0, 8,"300-470"); tQCDCompare_YieldAbsolute.setCellContent(1, 8,"VBF");
  tQCDCompare_YieldAbsolute.setCellContent(0, 9,"470-600"); tQCDCompare_YieldAbsolute.setCellContent(1, 9,"Inc");
  tQCDCompare_YieldAbsolute.setCellContent(0,10,"470-600"); tQCDCompare_YieldAbsolute.setCellContent(1,10,"VBF");
 
  return tQCDCompare_YieldAbsolute;
}

//_____________________________________________________
ICLatexTabular get_tQCDCompare_YieldTrigWgt(){

  ICLatexTabular tQCDCompare_YieldTrigWgt(9,11);
  tQCDCompare_YieldTrigWgt.setTabularPrecision(".2");
  
  tQCDCompare_YieldTrigWgt.setColumnDecorationBefore( 0,"|");
  tQCDCompare_YieldTrigWgt.setColumnDecorationAfter ( 0,"||");
  tQCDCompare_YieldTrigWgt.setColumnDecorationAfter ( 2,"||");
  tQCDCompare_YieldTrigWgt.setColumnDecorationAfter ( 4,"||");
  tQCDCompare_YieldTrigWgt.setColumnDecorationAfter ( 6,"||");
  tQCDCompare_YieldTrigWgt.setColumnDecorationAfter ( 8,"||");
  tQCDCompare_YieldTrigWgt.setColumnDecorationAfter (10,"|");
  
  tQCDCompare_YieldTrigWgt.setRowDecorationBefore(0,"\\hline");
  tQCDCompare_YieldTrigWgt.setRowDecorationBefore(1,"\\hline");
  tQCDCompare_YieldTrigWgt.setRowDecorationBefore(2,"\\hline \\hline");
  tQCDCompare_YieldTrigWgt.setRowDecorationAfter (8,"\\hline");
  
  tQCDCompare_YieldTrigWgt.setCellContent(1, 0,"Sample");
  tQCDCompare_YieldTrigWgt.setCellContent(0, 1, "80-120"); tQCDCompare_YieldTrigWgt.setCellContent(1, 1,"Inc");
  tQCDCompare_YieldTrigWgt.setCellContent(0, 2, "80-120"); tQCDCompare_YieldTrigWgt.setCellContent(1, 2,"VBF");
  tQCDCompare_YieldTrigWgt.setCellContent(0, 3,"120-170"); tQCDCompare_YieldTrigWgt.setCellContent(1, 3,"Inc");
  tQCDCompare_YieldTrigWgt.setCellContent(0, 4,"120-170"); tQCDCompare_YieldTrigWgt.setCellContent(1, 4,"VBF");
  tQCDCompare_YieldTrigWgt.setCellContent(0, 5,"170-300"); tQCDCompare_YieldTrigWgt.setCellContent(1, 5,"Inc");
  tQCDCompare_YieldTrigWgt.setCellContent(0, 6,"170-300"); tQCDCompare_YieldTrigWgt.setCellContent(1, 6,"VBF");
  tQCDCompare_YieldTrigWgt.setCellContent(0, 7,"300-470"); tQCDCompare_YieldTrigWgt.setCellContent(1, 7,"Inc");
  tQCDCompare_YieldTrigWgt.setCellContent(0, 8,"300-470"); tQCDCompare_YieldTrigWgt.setCellContent(1, 8,"VBF");
  tQCDCompare_YieldTrigWgt.setCellContent(0, 9,"470-600"); tQCDCompare_YieldTrigWgt.setCellContent(1, 9,"Inc");
  tQCDCompare_YieldTrigWgt.setCellContent(0,10,"470-600"); tQCDCompare_YieldTrigWgt.setCellContent(1,10,"VBF");
 
  return tQCDCompare_YieldTrigWgt;
}
  
//_____________________________________________________
ICLatexTabular get_tQCDCompare_YieldXsecWgt(){
  
  ICLatexTabular tQCDCompare_YieldXsecWgt(9,11);
  tQCDCompare_YieldXsecWgt.setTabularPrecision(".2");
  
  tQCDCompare_YieldXsecWgt.setColumnDecorationBefore( 0,"|");
  tQCDCompare_YieldXsecWgt.setColumnDecorationAfter ( 0,"||");
  tQCDCompare_YieldXsecWgt.setColumnDecorationAfter ( 2,"||");
  tQCDCompare_YieldXsecWgt.setColumnDecorationAfter ( 4,"||");
  tQCDCompare_YieldXsecWgt.setColumnDecorationAfter ( 6,"||");
  tQCDCompare_YieldXsecWgt.setColumnDecorationAfter ( 8,"||");
  tQCDCompare_YieldXsecWgt.setColumnDecorationAfter (10,"|");
  
  tQCDCompare_YieldXsecWgt.setRowDecorationBefore(0,"\\hline");
  tQCDCompare_YieldXsecWgt.setRowDecorationBefore(1,"\\hline");
  tQCDCompare_YieldXsecWgt.setRowDecorationBefore(2,"\\hline \\hline");
  tQCDCompare_YieldXsecWgt.setRowDecorationAfter (8,"\\hline");
  
  tQCDCompare_YieldXsecWgt.setCellContent(1, 0,"Sample");
  tQCDCompare_YieldXsecWgt.setCellContent(0, 1, "80-120"); tQCDCompare_YieldXsecWgt.setCellContent(1, 1,"Inc");
  tQCDCompare_YieldXsecWgt.setCellContent(0, 2, "80-120"); tQCDCompare_YieldXsecWgt.setCellContent(1, 2,"VBF");
  tQCDCompare_YieldXsecWgt.setCellContent(0, 3,"120-170"); tQCDCompare_YieldXsecWgt.setCellContent(1, 3,"Inc");
  tQCDCompare_YieldXsecWgt.setCellContent(0, 4,"120-170"); tQCDCompare_YieldXsecWgt.setCellContent(1, 4,"VBF");
  tQCDCompare_YieldXsecWgt.setCellContent(0, 5,"170-300"); tQCDCompare_YieldXsecWgt.setCellContent(1, 5,"Inc");
  tQCDCompare_YieldXsecWgt.setCellContent(0, 6,"170-300"); tQCDCompare_YieldXsecWgt.setCellContent(1, 6,"VBF");
  tQCDCompare_YieldXsecWgt.setCellContent(0, 7,"300-470"); tQCDCompare_YieldXsecWgt.setCellContent(1, 7,"Inc");
  tQCDCompare_YieldXsecWgt.setCellContent(0, 8,"300-470"); tQCDCompare_YieldXsecWgt.setCellContent(1, 8,"VBF");
  tQCDCompare_YieldXsecWgt.setCellContent(0, 9,"470-600"); tQCDCompare_YieldXsecWgt.setCellContent(1, 9,"Inc");
  tQCDCompare_YieldXsecWgt.setCellContent(0,10,"470-600"); tQCDCompare_YieldXsecWgt.setCellContent(1,10,"VBF");
  
  return tQCDCompare_YieldXsecWgt;
}

//_____________________________________________________
ICLatexTabular get_tQCDInc_YieldAbsolute(){

  ICLatexTabular tQCDInc_YieldAbsolute(8,13);
  tQCDInc_YieldAbsolute.setTabularPrecision(".0");
  
  
  
  tQCDInc_YieldAbsolute.setTabularColumnDecoration("|");
  tQCDInc_YieldAbsolute.setColumnDecorationAfter( 0,"||");
  
  tQCDInc_YieldAbsolute.setRowDecorationBefore(0,"\\hline");
  tQCDInc_YieldAbsolute.setRowDecorationBefore(1,"\\hline \\hline");
  tQCDInc_YieldAbsolute.setRowDecorationAfter (7,"\\hline");
  
  tQCDInc_YieldAbsolute.setCellContent(1, 0,"Sample");
  tQCDInc_YieldAbsolute.setCellContent(0, 1, "80-120");
  tQCDInc_YieldAbsolute.setCellContent(0, 2, "80-120");
  tQCDInc_YieldAbsolute.setCellContent(0, 3,"120-170");
  tQCDInc_YieldAbsolute.setCellContent(0, 4,"120-170");
  tQCDInc_YieldAbsolute.setCellContent(0, 5,"170-300");
  tQCDInc_YieldAbsolute.setCellContent(0, 6,"170-300");
  tQCDInc_YieldAbsolute.setCellContent(0, 7,"300-470");
  tQCDInc_YieldAbsolute.setCellContent(0, 8,"300-470");
  tQCDInc_YieldAbsolute.setCellContent(0, 9,"470-600");
  tQCDInc_YieldAbsolute.setCellContent(0,10,"470-600");
 
  tQCDInc_YieldAbsolute.setCellContent(0, 0,   "Sample");
  tQCDInc_YieldAbsolute.setCellContent(0, 1,    "30-50");
  tQCDInc_YieldAbsolute.setCellContent(0, 2,    "50-80");  
  tQCDInc_YieldAbsolute.setCellContent(0, 3,   "80-120");
  tQCDInc_YieldAbsolute.setCellContent(0, 4,  "120-170");
  tQCDInc_YieldAbsolute.setCellContent(0, 5,  "170-300");
  tQCDInc_YieldAbsolute.setCellContent(0, 6,  "300-470");
  tQCDInc_YieldAbsolute.setCellContent(0, 7,  "470-600"); 
  tQCDInc_YieldAbsolute.setCellContent(0, 8,  "600-800"); 
  tQCDInc_YieldAbsolute.setCellContent(0, 9, "800-1000"); 
  tQCDInc_YieldAbsolute.setCellContent(0,10,"1000-1400");
  tQCDInc_YieldAbsolute.setCellContent(0,11,"1400-1800");
  tQCDInc_YieldAbsolute.setCellContent(0,12,     "1800");
  
  return tQCDInc_YieldAbsolute;
}

//_____________________________________________________
ICLatexTabular get_tQCDInc_YieldTrigWgt(){
  
  ICLatexTabular tQCDInc_YieldTrigWgt(8,13);
  tQCDInc_YieldTrigWgt.setTabularPrecision(".2");
  
  tQCDInc_YieldTrigWgt.setTabularColumnDecoration("|");
  tQCDInc_YieldTrigWgt.setColumnDecorationAfter(0,"||");
  
  tQCDInc_YieldTrigWgt.setRowDecorationBefore(0,"\\hline");
  tQCDInc_YieldTrigWgt.setRowDecorationBefore(1,"\\hline \\hline");
  tQCDInc_YieldTrigWgt.setRowDecorationAfter (7,"\\hline");
  
  tQCDInc_YieldTrigWgt.setCellContent(0, 0,   "Sample");
  tQCDInc_YieldTrigWgt.setCellContent(0, 1,    "30-50");
  tQCDInc_YieldTrigWgt.setCellContent(0, 2,    "50-80");  
  tQCDInc_YieldTrigWgt.setCellContent(0, 3,   "80-120");
  tQCDInc_YieldTrigWgt.setCellContent(0, 4,  "120-170");
  tQCDInc_YieldTrigWgt.setCellContent(0, 5,  "170-300");
  tQCDInc_YieldTrigWgt.setCellContent(0, 6,  "300-470");
  tQCDInc_YieldTrigWgt.setCellContent(0, 7,  "470-600"); 
  tQCDInc_YieldTrigWgt.setCellContent(0, 8,  "600-800"); 
  tQCDInc_YieldTrigWgt.setCellContent(0, 9, "800-1000"); 
  tQCDInc_YieldTrigWgt.setCellContent(0,10,"1000-1400");
  tQCDInc_YieldTrigWgt.setCellContent(0,11,"1400-1800");
  tQCDInc_YieldTrigWgt.setCellContent(0,12,     "1800");
  
  return tQCDInc_YieldTrigWgt;
  
}

ICLatexTabular get_tQCDInc_YieldXsecWgt(){
  
  ICLatexTabular tQCDInc_YieldXsecWgt(8,13);
  tQCDInc_YieldXsecWgt.setTabularPrecision(".2");
  
  tQCDInc_YieldXsecWgt.setTabularColumnDecoration("|");
  tQCDInc_YieldXsecWgt.setColumnDecorationAfter(0,"||");
  
  tQCDInc_YieldXsecWgt.setRowDecorationBefore(0,"\\hline");
  tQCDInc_YieldXsecWgt.setRowDecorationBefore(1,"\\hline \\hline");
  tQCDInc_YieldXsecWgt.setRowDecorationAfter (7,"\\hline");
  
  tQCDInc_YieldXsecWgt.setCellContent(0, 0,   "Sample");
  tQCDInc_YieldXsecWgt.setCellContent(0, 1,    "30-50");
  tQCDInc_YieldXsecWgt.setCellContent(0, 2,    "50-80");  
  tQCDInc_YieldXsecWgt.setCellContent(0, 3,   "80-120");
  tQCDInc_YieldXsecWgt.setCellContent(0, 4,  "120-170");
  tQCDInc_YieldXsecWgt.setCellContent(0, 5,  "170-300");
  tQCDInc_YieldXsecWgt.setCellContent(0, 6,  "300-470");
  tQCDInc_YieldXsecWgt.setCellContent(0, 7,  "470-600"); 
  tQCDInc_YieldXsecWgt.setCellContent(0, 8,  "600-800"); 
  tQCDInc_YieldXsecWgt.setCellContent(0, 9, "800-1000"); 
  tQCDInc_YieldXsecWgt.setCellContent(0,10,"1000-1400");
  tQCDInc_YieldXsecWgt.setCellContent(0,11,"1400-1800");
  tQCDInc_YieldXsecWgt.setCellContent(0,12,     "1800");
  
  return tQCDInc_YieldXsecWgt;
}

ICLatexTabular get_tMCSummary_YieldAbsolute(){
  
  ICLatexTabular tMCSummary_YieldAbsolute(8,12);
  tMCSummary_YieldAbsolute.setTabularPrecision(".0");
  
  tMCSummary_YieldAbsolute.setTabularColumnDecoration("|");
  tMCSummary_YieldAbsolute.setColumnDecorationAfter  ( 0,"||");
  tMCSummary_YieldAbsolute.setColumnDecorationAfter  (10,"||");
  
  tMCSummary_YieldAbsolute.setRowDecorationBefore(0,"\\hline");
  tMCSummary_YieldAbsolute.setRowDecorationBefore(1,"\\hline \\hline");
  tMCSummary_YieldAbsolute.setRowDecorationAfter (7,"\\hline");
  
  tMCSummary_YieldAbsolute.setCellContent(0, 0,"Sample");
  tMCSummary_YieldAbsolute.setCellContent(0, 1,"Data");
  tMCSummary_YieldAbsolute.setCellContent(0, 2,"QCD Inc");
  tMCSummary_YieldAbsolute.setCellContent(0, 3,"QCD VBF");
  tMCSummary_YieldAbsolute.setCellContent(0, 4,"$t\\bar{t}$");
  tMCSummary_YieldAbsolute.setCellContent(0, 5,"W+Jets");
  tMCSummary_YieldAbsolute.setCellContent(0, 6,"VV");
  tMCSummary_YieldAbsolute.setCellContent(0, 7,"G+Jets");
  tMCSummary_YieldAbsolute.setCellContent(0, 8,"EWK V+2j");
  tMCSummary_YieldAbsolute.setCellContent(0, 9,"Z+Jets");
  tMCSummary_YieldAbsolute.setCellContent(0,10,"DY");
  tMCSummary_YieldAbsolute.setCellContent(0,11,"MC Total");
  
  return tMCSummary_YieldAbsolute;
}

//_____________________________________________________
ICLatexTabular get_tMCSummary_YieldXsecWgt(){
  
  ICLatexTabular tMCSummary_YieldXsecWgt(8,12);
  tMCSummary_YieldXsecWgt.setTabularPrecision(".2");
  
  tMCSummary_YieldXsecWgt.setTabularColumnDecoration("|");
  tMCSummary_YieldXsecWgt.setColumnDecorationAfter  ( 0,"||");
  tMCSummary_YieldXsecWgt.setColumnDecorationAfter  (10,"||");
  
  tMCSummary_YieldXsecWgt.setRowDecorationBefore(0,"\\hline");
  tMCSummary_YieldXsecWgt.setRowDecorationBefore(1,"\\hline \\hline");
  tMCSummary_YieldXsecWgt.setRowDecorationAfter (7,"\\hline");
  
  tMCSummary_YieldXsecWgt.setCellContent(0, 0,"Sample");
  tMCSummary_YieldXsecWgt.setCellContent(0, 1,"Data");
  tMCSummary_YieldXsecWgt.setCellContent(0, 2,"QCD Inc");
  tMCSummary_YieldXsecWgt.setCellContent(0, 3,"QCD VBF");
  tMCSummary_YieldXsecWgt.setCellContent(0, 4,"$t\\bar{t}$");
  tMCSummary_YieldXsecWgt.setCellContent(0, 5,"W+Jets");
  tMCSummary_YieldXsecWgt.setCellContent(0, 6,"VV");
  tMCSummary_YieldXsecWgt.setCellContent(0, 7,"G+Jets");
  tMCSummary_YieldXsecWgt.setCellContent(0, 8,"EWK V+2j");
  tMCSummary_YieldXsecWgt.setCellContent(0, 9,"Z+Jets");
  tMCSummary_YieldXsecWgt.setCellContent(0,10,"DY");
  tMCSummary_YieldXsecWgt.setCellContent(0,11,"MC Total");
  
  return tMCSummary_YieldXsecWgt;
}

//_____________________________________________________
ICLatexTabular get_tQCDSummary_YieldWeighted(){
  
  ICLatexTabular tQCDSummary_YieldWeighted(8,5);
  tQCDSummary_YieldWeighted.setTabularPrecision(".2");
  
  tQCDSummary_YieldWeighted.setTabularColumnDecoration("|");
  tQCDSummary_YieldWeighted.setColumnDecorationAfter  (0,"||");
  tQCDSummary_YieldWeighted.setColumnDecorationAfter  (2,"||");
  
  tQCDSummary_YieldWeighted.setRowDecorationBefore(0,"\\hline");
  tQCDSummary_YieldWeighted.setRowDecorationBefore(1,"\\hline \\hline");
  tQCDSummary_YieldWeighted.setRowDecorationAfter (7,"\\hline");
  
  tQCDSummary_YieldWeighted.setCellContent(0, 0,"Sample");
  tQCDSummary_YieldWeighted.setCellContent(0, 1,"QCD Inc");
  tQCDSummary_YieldWeighted.setCellContent(0, 2,"QCD VBF");
  tQCDSummary_YieldWeighted.setCellContent(0, 3,"Data");
  tQCDSummary_YieldWeighted.setCellContent(0, 4,"Total");
  
  return tQCDSummary_YieldWeighted;
}