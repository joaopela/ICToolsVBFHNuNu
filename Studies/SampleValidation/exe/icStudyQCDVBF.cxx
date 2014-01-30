// TODO: Description

// ICTools includes
#include "Latex/Table/interface/ICLatexTable.h"
#include "Latex/Table/interface/ICLatexTabular.h"
#include "Latex/Table/interface/ICLatexCaption.h"
#include "Plots/Tools/interface/ICPlotFwd.h"
#include "Plots/Tools/interface/ICPlotCollection.h"

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

ICLatexTabular get_tabXSec();
ICLatexTabular get_tQCDCompare_YieldAbsolute();
ICLatexTabular get_tQCDCompare_YieldTrigWgt();
ICLatexTabular get_tQCDCompare_YieldXsecWgt();

ICLatexTabular get_tQCDInc_YieldAbsolute();
ICLatexTabular get_tQCDInc_YieldTrigWgt();
ICLatexTabular get_tQCDInc_YieldXsecWgt();

ICLatexTabular get_tabEvTotalWeighted();
ICLatexTabular get_tabEvAllTotalWeighted();

int main(int argc, char *argv[]){

  double lumi = 19500.3;

  //_________________________________________
  // Samples to be used
  //_________________________________________
  map<string,TFile*> files;
  files["Data_MET-2012A-13Jul2012-v1"]  = new TFile("Data_MET-2012A-13Jul2012-v1.root");
  files["Data_MET-2012A-06Aug2012-v1"]  = new TFile("Data_MET-2012A-06Aug2012-v1.root");
  files["Data_MET-2012B-13Jul2012-v1"]  = new TFile("Data_MET-2012B-13Jul2012-v1.root");
  files["Data_MET-2012C-24Aug2012-v1"]  = new TFile("Data_MET-2012C-24Aug2012-v1.root");
  files["Data_MET-2012C-11Dec2012-v1"]  = new TFile("Data_MET-2012C-11Dec2012-v1.root");
  files["Data_MET-2012C-PromptReco-v2"] = new TFile("Data_MET-2012C-PromptReco-v2.root");
  files["Data_MET-2012D-PromptReco-v1"] = new TFile("Data_MET-2012D-PromptReco-v1.root");

  files["QCD-Pt-30to50"]       = new TFile("MC_QCD-Pt-30to50-pythia6.root");
  files["QCD-Pt-50to80"]       = new TFile("MC_QCD-Pt-50to80-pythia6.root");
  files["QCD-Pt-80to120"]      = new TFile("MC_QCD-Pt-80to120-pythia6.root");
  files["QCD-Pt-120to170"]     = new TFile("MC_QCD-Pt-120to170-pythia6.root");
  files["QCD-Pt-170to300"]     = new TFile("MC_QCD-Pt-170to300-pythia6.root");
  files["QCD-Pt-300to470"]     = new TFile("MC_QCD-Pt-300to470-pythia6.root");
  files["QCD-Pt-470to600"]     = new TFile("MC_QCD-Pt-470to600-pythia6.root");
  files["QCD-Pt-600to800"]     = new TFile("MC_QCD-Pt-600to800-pythia6.root");
  files["QCD-Pt-800to1000"]    = new TFile("MC_QCD-Pt-800to1000-pythia6.root");  
  files["QCD-Pt-1000to1400"]   = new TFile("MC_QCD-Pt-1000to1400-pythia6.root");  
  files["QCD-Pt-1400to1800"]   = new TFile("MC_QCD-Pt-1400to1800-pythia6.root");
  files["QCD-Pt-1800"]         = new TFile("MC_QCD-Pt-1800-pythia6.root");
  
  files["QCD_VBF-Pt-80to120"]  = new TFile("MC_QCD-Pt-80to120_VBF-MET40.root");
  files["QCD_VBF-Pt-120to170"] = new TFile("MC_QCD-Pt-120to170_VBF-MET40.root");
  files["QCD_VBF-Pt-170to300"] = new TFile("MC_QCD-Pt-170to300_VBF-MET40.root");
  files["QCD_VBF-Pt-300to470"] = new TFile("MC_QCD-Pt-300to470_VBF-MET40.root");
  files["QCD_VBF-Pt-470to600"] = new TFile("MC_QCD-Pt-470to600_VBF-MET40.root");
  
  // TT
  files["TTJets"] = new TFile("MC_TTJets.root");

  //powheg samples
  files["TT-v1"] = new TFile("MC_TT-v1.root");
  files["TT-v2"] = new TFile("MC_TT-v2.root");

  //
  files["T-tW"]                       = new TFile("MC_T-tW.root");
  files["Tbar-tW"]                    = new TFile("MC_Tbar-tW.root");
  files["SingleT-s-powheg-tauola"]    = new TFile("MC_SingleT-s-powheg-tauola.root");
  files["SingleTBar-s-powheg-tauola"] = new TFile("MC_SingleTBar-s-powheg-tauola.root");
  files["SingleT-t-powheg-tauola"]    = new TFile("MC_SingleT-t-powheg-tauola.root");
  files["SingleTBar-t-powheg-tauola"] = new TFile("MC_SingleTBar-t-powheg-tauola.root");
  files["WW-pythia6-tauola"]          = new TFile("MC_WW-pythia6-tauola.root");       
  files["WZ-pythia6-tauola"]          = new TFile("MC_WZ-pythia6-tauola.root");       
  files["ZZ-pythia6-tauola"]          = new TFile("MC_ZZ-pythia6-tauola.root");        
  files["W1JetsToLNu_enu"]            = new TFile("MC_W1JetsToLNu_enu.root");         
  files["W2JetsToLNu_enu"]            = new TFile("MC_W2JetsToLNu_enu.root");         
  files["W3JetsToLNu_enu"]            = new TFile("MC_W3JetsToLNu_enu.root");         
  files["W4JetsToLNu_enu"]            = new TFile("MC_W4JetsToLNu_enu.root");       
  files["WJetsToLNu-v1_enu"]          = new TFile("MC_WJetsToLNu-v1_enu.root");       
  files["WJetsToLNu-v2_enu"]          = new TFile("MC_WJetsToLNu-v2_enu.root");        
  files["W1JetsToLNu_munu"]           = new TFile("MC_W1JetsToLNu_munu.root");        
  files["W2JetsToLNu_munu"]           = new TFile("MC_W2JetsToLNu_munu.root");        
  files["W3JetsToLNu_munu"]           = new TFile("MC_W3JetsToLNu_munu.root");        
  files["W4JetsToLNu_munu"]           = new TFile("MC_W4JetsToLNu_munu.root");      
  files["WJetsToLNu-v1_munu"]         = new TFile("MC_WJetsToLNu-v1_munu.root");      
  files["WJetsToLNu-v2_munu"]         = new TFile("MC_WJetsToLNu-v2_munu.root");       
  files["W1JetsToLNu_taunu"]          = new TFile("MC_W1JetsToLNu_taunu.root");       
  files["W2JetsToLNu_taunu"]          = new TFile("MC_W2JetsToLNu_taunu.root");       
  files["W3JetsToLNu_taunu"]          = new TFile("MC_W3JetsToLNu_taunu.root");       
  files["W4JetsToLNu_taunu"]          = new TFile("MC_W4JetsToLNu_taunu.root");     
  files["WJetsToLNu-v1_taunu"]        = new TFile("MC_WJetsToLNu-v1_taunu.root");     
  files["WJetsToLNu-v2_taunu"]        = new TFile("MC_WJetsToLNu-v2_taunu.root");    
  files["DYJetsToLL"]                 = new TFile("MC_DYJetsToLL.root");             
  files["DY1JetsToLL"]                = new TFile("MC_DY1JetsToLL.root");             
  files["DY2JetsToLL"]                = new TFile("MC_DY2JetsToLL.root");             
  files["DY3JetsToLL"]                = new TFile("MC_DY3JetsToLL.root");             
  files["DY4JetsToLL"]                = new TFile("MC_DY4JetsToLL.root");  
  files["ZJetsToNuNu_100_HT_200"]     = new TFile("MC_ZJetsToNuNu_100_HT_200.root");  
  files["ZJetsToNuNu_200_HT_400"]     = new TFile("MC_ZJetsToNuNu_200_HT_400.root");  
  files["ZJetsToNuNu_400_HT_inf"]     = new TFile("MC_ZJetsToNuNu_400_HT_inf.root");   
  files["ZJetsToNuNu_50_HT_100"]      = new TFile("MC_ZJetsToNuNu_50_HT_100.root");
  files["GJets-HT-200To400-madgraph"] = new TFile("MC_GJets-HT-200To400-madgraph.root");
  files["GJets-HT-400ToInf-madgraph"] = new TFile("MC_GJets-HT-400ToInf-madgraph.root");
  files["VBF_HToZZTo4Nu_M-120"]       = new TFile("MC_VBF_HToZZTo4Nu_M-120.root");    
  files["EWK-Z2j"]                    = new TFile("MC_EWK-Z2j.root");            
  files["EWK-Z2jiglep"]               = new TFile("MC_EWK-Z2jiglep.root");             
  files["EWK-W2jminus_enu"]           = new TFile("MC_EWK-W2jminus_enu.root");         
  files["EWK-W2jplus_enu"]            = new TFile("MC_EWK-W2jplus_enu.root");          
  files["EWK-W2jminus_munu"]          = new TFile("MC_EWK-W2jminus_munu.root");        
  files["EWK-W2jplus_munu"]           = new TFile("MC_EWK-W2jplus_munu.root");         
  files["EWK-W2jminus_taunu"]         = new TFile("MC_EWK-W2jminus_taunu.root");       
  files["EWK-W2jplus_taunu"]          = new TFile("MC_EWK-W2jplus_taunu.root");        
  files["WGamma"]                     = new TFile("MC_WGamma.root");                   
  
  //_________________________________________
  map<string,double> xsec;
  xsec["QCD-Pt-30to50"]       = 66285328;
  xsec["QCD-Pt-50to80"]       =  8148778.0;
  xsec["QCD-Pt-80to120"]      =  1033680.0;
  xsec["QCD-Pt-120to170"]     =   156293.3;
  xsec["QCD-Pt-170to300"]     =    34138.15;
  xsec["QCD-Pt-300to470"]     =     1759.549;
  xsec["QCD-Pt-470to600"]     =      113.8791;
  xsec["QCD-Pt-600to800"]     =       26.9921;
  xsec["QCD-Pt-800to1000"]    =        3.550036;
  xsec["QCD-Pt-1000to1400"]   =        0.737844;
  xsec["QCD-Pt-1400to1800"]   =        0.03352235;
  xsec["QCD-Pt-1800"]         =        0.001829005;
  
  xsec["QCD_VBF-Pt-80to120"]  =  1033680.0;
  xsec["QCD_VBF-Pt-120to170"] =   156293.3;
  xsec["QCD_VBF-Pt-170to300"] =    34138.15;
  xsec["QCD_VBF-Pt-300to470"] =     1759.549;
  xsec["QCD_VBF-Pt-470to600"] =      113.8791;

  // MC TTbar
  xsec["TTJets"]                      =  245.8;
  xsec["TT-v1"]                       =  211.0;
  xsec["TT-v2"]                       =  211.0;
  
  // Single top
  xsec["T-tW"]                        =  11.1;
  xsec["Tbar-tW"]                     =  11.1;
  xsec["SingleT-s-powheg-tauola"]     =  3.79;
  xsec["SingleTBar-s-powheg-tauola"]  =  1.76;
  xsec["SingleT-t-powheg-tauola"]     =  56.4;
  xsec["SingleTBar-t-powheg-tauola"]  =  30.7;
  
  // MC Dibosons
  xsec["WW-pythia6-tauola"] = 54.838;
  xsec["WZ-pythia6-tauola"] = 33.21;
  xsec["ZZ-pythia6-tauola"] = 17.654;
  xsec["WGamma"]            = 461.6;
  
  xsec["DYJJ01JetsToLL_M-50_MJJ-200"] =  1.4;

  xsec["W1JetsToLNu_enu"]     = 37509;
  xsec["W2JetsToLNu_enu"]     = 37509;
  xsec["W3JetsToLNu_enu"]     = 37509;
  xsec["W4JetsToLNu_enu"]     = 37509;
  xsec["WJetsToLNu-v1_enu"]   = 37509;
  xsec["WJetsToLNu-v2_enu"]   = 37509;
  xsec["W1JetsToLNu_munu"]    = 37509;
  xsec["W2JetsToLNu_munu"]    = 37509;
  xsec["W3JetsToLNu_munu"]    = 37509;
  xsec["W4JetsToLNu_munu"]    = 37509;
  xsec["WJetsToLNu-v1_munu"]  = 37509;
  xsec["WJetsToLNu-v2_munu"]  = 37509;
  xsec["W1JetsToLNu_taunu"]   = 37509;
  xsec["W2JetsToLNu_taunu"]   = 37509;
  xsec["W3JetsToLNu_taunu"]   = 37509;
  xsec["W4JetsToLNu_taunu"]   = 37509;
  xsec["WJetsToLNu-v1_taunu"] = 37509;
  xsec["WJetsToLNu-v2_taunu"] = 37509;

  xsec["DYJetsToLL"]  =  3503.7;
  xsec["DY1JetsToLL"]  =  3503.7;
  xsec["DY2JetsToLL"]  =  3503.7;
  xsec["DY3JetsToLL"]  =  3503.7;
  xsec["DY4JetsToLL"]  =  3503.7;
  xsec["DYJetsToLL_PtZ-100-madgraph"] =  40.5;

  xsec["ZJetsToNuNu_50_HT_100"]       =  381.2;
  xsec["ZJetsToNuNu_100_HT_200"]      =  160.3;
  xsec["ZJetsToNuNu_200_HT_400"]      =  41.49;
  xsec["ZJetsToNuNu_400_HT_inf"]      =  5.274;
  
  xsec["GJets-HT-200To400-madgraph"]  =  960.5;
  xsec["GJets-HT-400ToInf-madgraph"]  =  107.5;

  // MC VBF Higgs to invisible (signal)
  xsec["VBF_HToZZTo4Nu_M-120"]  =  1.649;
  xsec["VBF_HToZZTo4Nu_M-150"]  =  1.280;
  xsec["VBF_HToZZTo4Nu_M-200"]  =  0.8685;
  xsec["VBF_HToZZTo4Nu_M-300"]  =  0.4408;
  xsec["VBF_HToZZTo4Nu_M-400"]  =  0.2543;

  // MC VBF Higgs to invisible POWHEG (signal)
  xsec["Powheg-Htoinv-mH110"]  =  1.809;
  xsec["Powheg-Htoinv-mH125"]  =  1.578;
  xsec["Powheg-Htoinv-mH150"]  =  1.280;
  xsec["Powheg-Htoinv-mH200"]  =  0.8685;
  xsec["Powheg-Htoinv-mH300"]  =  0.4408;
  xsec["Powheg-Htoinv-mH400"]  =  0.2543;

  xsec["EWK-Z2j"]            =  0.888;
  xsec["EWK-Z2jiglep"]       =  1.776;
  xsec["EWK-W2jminus"]       =  4.09;
  xsec["EWK-W2jplus"]        =  6.48;
  xsec["EWK-W2jminus_enu"]   =  4.09;
  xsec["EWK-W2jplus_enu"]    =  6.48;
  xsec["EWK-W2jminus_munu"]  =  4.09;
  xsec["EWK-W2jplus_munu"]   =  6.48;
  xsec["EWK-W2jminus_taunu"] =  4.09;
  xsec["EWK-W2jplus_taunu"]  =  6.48;  
  
  //_________________________________________
  map<string,double> events;  
  events["QCD-Pt-30to50"]     = 5910000.0;
  events["QCD-Pt-50to80"]     = 5998860.0;
  events["QCD-Pt-80to120"]    = 5994864.0;
  events["QCD-Pt-120to170"]   = 5955732.0;
  events["QCD-Pt-170to300"]   = 5814398.0;
  events["QCD-Pt-300to470"]   = 5978500.0;
  events["QCD-Pt-470to600"]   = 3964848.0;
  events["QCD-Pt-600to800"]   = 3996864.0;
  events["QCD-Pt-800to1000"]  = 3998563.0;
  events["QCD-Pt-1000to1400"] = 1904088.0;
  events["QCD-Pt-1400to1800"] = 1910062.0;
  events["QCD-Pt-1800"]       =  947586.0;
   
  events["QCD_VBF-Pt-80to120"]  = 39376000000;
  events["QCD_VBF-Pt-120to170"] =  7000000000;
  events["QCD_VBF-Pt-170to300"] =  1375000000;
  events["QCD_VBF-Pt-300to470"] =    80000000;
  events["QCD_VBF-Pt-470to600"] =    25000000;

  events["TTJets"] =  6923750.0;
  events["TT-v1"]  =  28150723;
  events["TT-v2"]  =  28150723;

  events["T-tW"]    =  497658.0;
  events["Tbar-tW"] =  493460.0;
  
  events["SingleT-s-powheg-tauola"]    =  259961.0;
  events["SingleT-t-powheg-tauola"]    =  3758227.0;
  events["SingleTBar-s-powheg-tauola"] =  139974.0;
  events["SingleTBar-t-powheg-tauola"] =  1935072.0;

  events["WW-pythia6-tauola"]           =  10000431.0;
  events["WZ-pythia6-tauola"]           =  10000283.0;
  events["ZZ-pythia6-tauola"]           =  9799908.0;
  events["DYJJ01JetsToLL_M-50_MJJ-200"] =  510501.0;

  events["W1JetsToLNu_enu"]     =  76102995.0;
  events["W2JetsToLNu_enu"]     =  76102995.0;
  events["W3JetsToLNu_enu"]     =  76102995.0;
  events["W4JetsToLNu_enu"]     =  76102995.0;
  events["WJetsToLNu-v1_enu"]   =  76102995.0;
  events["WJetsToLNu-v2_enu"]   =  76102995.0;
  events["W1JetsToLNu_munu"]    =  76102995.0;
  events["W2JetsToLNu_munu"]    =  76102995.0;
  events["W3JetsToLNu_munu"]    =  76102995.0;
  events["W4JetsToLNu_munu"]    =  76102995.0;
  events["WJetsToLNu-v1_munu"]  =  76102995.0;
  events["WJetsToLNu-v2_munu"]  =  76102995.0;
  events["W1JetsToLNu_taunu"]   =  76102995.0;
  events["W2JetsToLNu_taunu"]   =  76102995.0;
  events["W3JetsToLNu_taunu"]   =  76102995.0;
  events["W4JetsToLNu_taunu"]   =  76102995.0;
  events["WJetsToLNu-v1_taunu"] =  76102995.0;
  events["WJetsToLNu-v2_taunu"] =  76102995.0;
  
  events["DYJetsToLL"]                  =  30459503.0;
  events["DY1JetsToLL"]                 =  30459503.0;
  events["DY2JetsToLL"]                 =  30459503.0;
  events["DY3JetsToLL"]                 =  30459503.0;
  events["DY4JetsToLL"]                 =  30459503.0;
  events["DYJetsToLL_PtZ-100-madgraph"] =  2632137.0;
  
  events["ZJetsToNuNu_50_HT_100"]  =  4040980.0;
  events["ZJetsToNuNu_100_HT_200"] =  4416646.0;
  events["ZJetsToNuNu_200_HT_400"] =  5055885.0;
  events["ZJetsToNuNu_400_HT_inf"] =  1006928.0;

  events["GJets-HT-200To400-madgraph"] =  58597147.0;
  events["GJets-HT-400ToInf-madgraph"] =  42391678.0;

  events["VBF_HToZZTo4Nu_M-120"] =  100118.0;
  events["VBF_HToZZTo4Nu_M-150"] =  100280.0;
  events["VBF_HToZZTo4Nu_M-200"] =  100118.0;
  events["VBF_HToZZTo4Nu_M-300"] =  100076.0;
  events["VBF_HToZZTo4Nu_M-400"] =  100083.0;

  events["Powheg-Htoinv-mH110"] =  99885.0;
  events["Powheg-Htoinv-mH125"] =  99885.0;
  events["Powheg-Htoinv-mH150"] =  99874.0;
  events["Powheg-Htoinv-mH200"] =  49922.0;
  events["Powheg-Htoinv-mH300"] =  49945.0;
  events["Powheg-Htoinv-mH400"] =  49964.0;

  events["EWK-Z2j"]            =  2978717;
  events["EWK-Z2jiglep"]       =  2978717;
  events["EWK-W2jminus"]       =  4696648;
  events["EWK-W2jminus_enu"]   =  4696648;
  events["EWK-W2jminus_munu"]  =  4696648;
  events["EWK-W2jminus_taunu"] =  4696648;
  events["EWK-W2jplus"]        =  6776164;
  events["EWK-W2jplus_enu"]    =  6776164;
  events["EWK-W2jplus_munu"]   =  6776164;
  events["EWK-W2jplus_taunu"]  =  6776164;
  
  events["WGamma"] =  4772358;
  
  
  vector<string> samples;
  samples.push_back("QCD-Pt-30to50");     
  samples.push_back("QCD-Pt-50to80");     
  samples.push_back("QCD-Pt-80to120");    
  samples.push_back("QCD-Pt-120to170");   
  samples.push_back("QCD-Pt-170to300");  
  samples.push_back("QCD-Pt-300to470");  
  samples.push_back("QCD-Pt-470to600");  
  samples.push_back("QCD-Pt-600to800");  
  samples.push_back("QCD-Pt-800to1000");  
  samples.push_back("QCD-Pt-1000to1400"); 
  samples.push_back("QCD-Pt-1400to1800");
  samples.push_back("QCD-Pt-1800");
  samples.push_back("QCD_VBF-Pt-80to120");
  samples.push_back("QCD_VBF-Pt-120to170");
  samples.push_back("QCD_VBF-Pt-170to300");
  samples.push_back("QCD_VBF-Pt-300to470");
  samples.push_back("QCD_VBF-Pt-470to600");
  
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
  vector<string> samplesQCDIncAll;
  samplesQCDIncAll.push_back("QCD-Pt-30to50");
  samplesQCDIncAll.push_back("QCD-Pt-50to80");    
  samplesQCDIncAll.push_back("QCD-Pt-80to120");   
  samplesQCDIncAll.push_back("QCD-Pt-120to170");  
  samplesQCDIncAll.push_back("QCD-Pt-170to300"); 
  samplesQCDIncAll.push_back("QCD-Pt-300to470"); 
  samplesQCDIncAll.push_back("QCD-Pt-470to600"); 
  samplesQCDIncAll.push_back("QCD-Pt-600to800"); 
  samplesQCDIncAll.push_back("QCD-Pt-800to1000"); 
  samplesQCDIncAll.push_back("QCD-Pt-1000to1400");
  samplesQCDIncAll.push_back("QCD-Pt-1400to1800");
  samplesQCDIncAll.push_back("QCD-Pt-1800");
  
  vector<string> samplesQCDInc;
  samplesQCDInc.push_back("QCD-Pt-80to120"); 
  samplesQCDInc.push_back("QCD-Pt-120to170");
  samplesQCDInc.push_back("QCD-Pt-170to300");  
  samplesQCDInc.push_back("QCD-Pt-300to470");  
  samplesQCDInc.push_back("QCD-Pt-470to600");
  
  vector<string> samplesQCDVBF;
  samplesQCDVBF.push_back("QCD_VBF-Pt-80to120");
  samplesQCDVBF.push_back("QCD_VBF-Pt-120to170");
  samplesQCDVBF.push_back("QCD_VBF-Pt-170to300");
  samplesQCDVBF.push_back("QCD_VBF-Pt-300to470");
  samplesQCDVBF.push_back("QCD_VBF-Pt-470to600");

  // QCD VBF + other
  vector<string> samples_qcdvbfextra;
  samples_qcdvbfextra.push_back("QCD-Pt-30to50");
  samples_qcdvbfextra.push_back("QCD-Pt-50to80");    
  samples_qcdvbfextra.push_back("QCD_VBF-Pt-80to120");   
  samples_qcdvbfextra.push_back("QCD_VBF-Pt-120to170");  
  samples_qcdvbfextra.push_back("QCD_VBF-Pt-170to300"); 
  samples_qcdvbfextra.push_back("QCD_VBF-Pt-300to470"); 
  samples_qcdvbfextra.push_back("QCD_VBF-Pt-470to600"); 
  samples_qcdvbfextra.push_back("QCD-Pt-600to800"); 
  samples_qcdvbfextra.push_back("QCD-Pt-800to1000"); 
  samples_qcdvbfextra.push_back("QCD-Pt-1000to1400");
  samples_qcdvbfextra.push_back("QCD-Pt-1400to1800");
  samples_qcdvbfextra.push_back("QCD-Pt-1800");

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
  samples_vv.push_back("WW-pythia6-tauola");
  samples_vv.push_back("WZ-pythia6-tauola");
  samples_vv.push_back("ZZ-pythia6-tauola");
  samples_vv.push_back("WGamma");
  
  // Samples W+jets (Correct)
  vector<string> samples_wjets;     
  samples_wjets.push_back("WJetsToLNu-v1_enu");  
  samples_wjets.push_back("WJetsToLNu-v2_enu");  
  samples_wjets.push_back("W1JetsToLNu_enu");    
  samples_wjets.push_back("W2JetsToLNu_enu");    
  samples_wjets.push_back("W3JetsToLNu_enu");    
  samples_wjets.push_back("W4JetsToLNu_enu");    
  samples_wjets.push_back("WJetsToLNu-v1_munu"); 
  samples_wjets.push_back("WJetsToLNu-v2_munu"); 
  samples_wjets.push_back("W1JetsToLNu_munu");   
  samples_wjets.push_back("W2JetsToLNu_munu");   
  samples_wjets.push_back("W3JetsToLNu_munu");   
  samples_wjets.push_back("W4JetsToLNu_munu");   
  samples_wjets.push_back("W1JetsToLNu_taunu");  
  samples_wjets.push_back("W2JetsToLNu_taunu");  
  samples_wjets.push_back("W3JetsToLNu_taunu");  
  samples_wjets.push_back("W4JetsToLNu_taunu");  
  samples_wjets.push_back("WJetsToLNu-v1_taunu");
  samples_wjets.push_back("WJetsToLNu-v2_taunu");  
  
  // Samples top (Correct)
  vector<string> samples_ttbar;
  samples_ttbar.push_back("TTJets");
  samples_ttbar.push_back("T-tW");
  samples_ttbar.push_back("Tbar-tW");
  samples_ttbar.push_back("SingleT-s-powheg-tauola");
  samples_ttbar.push_back("SingleTBar-s-powheg-tauola");
  samples_ttbar.push_back("SingleT-t-powheg-tauola");
  samples_ttbar.push_back("SingleTBar-t-powheg-tauola");  
  
  // Samples G+Jets (Correct)
  vector<string> samples_gjets;
  samples_gjets.push_back("GJets-HT-200To400-madgraph");
  samples_gjets.push_back("GJets-HT-400ToInf-madgraph");
  
  // Samples EWK
  vector<string> samples_ewk;
  samples_ewk.push_back("EWK-Z2j");
  samples_ewk.push_back("EWK-Z2jiglep");
  samples_ewk.push_back("EWK-W2jminus_enu");
  samples_ewk.push_back("EWK-W2jplus_enu");
  samples_ewk.push_back("EWK-W2jminus_munu");
  samples_ewk.push_back("EWK-W2jplus_munu");
  samples_ewk.push_back("EWK-W2jminus_taunu");
  samples_ewk.push_back("EWK-W2jplus_taunu");

  // Samples ZJets
  vector<string> samples_zjets;
  samples_zjets.push_back("ZJetsToNuNu_100_HT_200");
  samples_zjets.push_back("ZJetsToNuNu_200_HT_400");
  samples_zjets.push_back("ZJetsToNuNu_400_HT_inf");
  samples_zjets.push_back("ZJetsToNuNu_50_HT_100");
  
  // Samples DY
  vector<string> samples_dy;
  samples_dy.push_back("DYJetsToLL");
  samples_dy.push_back("DY1JetsToLL");
  samples_dy.push_back("DY2JetsToLL");
  samples_dy.push_back("DY3JetsToLL");
  samples_dy.push_back("DY4JetsToLL");
  
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
      
      TH1F *hInc,*hVBF;
      TCanvas *canv = new TCanvas();

      MapString_ICH1F mPlots  = MapString_ICH1F(files,Form("%s/%s",cuts[c].c_str(),hists[h].c_str()));
      mPlots.Scale(wgt);  // removed since already included
      hInc = mPlots.getMerged(Form("QCDInc_%s_%s",cuts[c].c_str(),hists[h].c_str()),samplesQCDInc);
      hVBF = mPlots.getMerged(Form("QCDVBF_%s_%s",cuts[c].c_str(),hists[h].c_str()),samplesQCDVBF);

      if(hInc->Integral()!=0){hInc->Scale(1/hInc->Integral());}
      if(hVBF->Integral()!=0){hVBF->Scale(1/hVBF->Integral());}      
      
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
      else if(cuts[c]=="CJVpass"            && hists[h]=="jpt_1") {int r=20; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="CJVpass"            && hists[h]=="jpt_2") {int r=20; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="CJVpass"            && hists[h]=="jeta_1"){int r= 4; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="CJVpass"            && hists[h]=="jeta_2"){int r= 4; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="CJVpass"            && hists[h]=="met")   {int r= 8; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,300);}
      else if(cuts[c]=="CJVpass"            && hists[h]=="mjj")   {int r=50; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,2500);}     
      else if(cuts[c]=="DPhiSIGNAL_CJVpass" && hists[h]=="jpt_1") {int r=20; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="DPhiSIGNAL_CJVpass" && hists[h]=="jpt_2") {int r=20; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,500);}
      else if(cuts[c]=="DPhiSIGNAL_CJVpass" && hists[h]=="jeta_1"){int r= 4; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="DPhiSIGNAL_CJVpass" && hists[h]=="jeta_2"){int r= 4; hInc->Rebin(r);hVBF->Rebin(r);}
      else if(cuts[c]=="DPhiSIGNAL_CJVpass" && hists[h]=="met")   {int r= 8; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,300);}
      else if(cuts[c]=="DPhiSIGNAL_CJVpass" && hists[h]=="mjj")   {int r=50; hInc->Rebin(r);hVBF->Rebin(r);hInc->SetAxisRange(0,2500);} 
      
      hVBF->SetLineColor(kRed);
      hInc->Draw();
      hVBF->Draw("same");
      canv->SaveAs(Form("%s_%s.pdf",cuts[c].c_str(),hists[h].c_str()));
      
      delete hInc;
      delete hVBF;
      delete canv;
    } 
  }
  
  //_________________________________________________________________________________________________
  // Filling table: Cross sections
  //_________________________________________________________________________________________________
  ICLatexTabular tabXSec = get_tabXSec();

  for(unsigned i=0; i<samples.size(); i++){
    
    string* s = &(samples[i]);
    
    tabXSec.setCellContent(int(i+1),0,Form("\\verb|%s|",(*s).c_str()));//samples[i]);  
    tabXSec.setCellContent(int(i+1),1,xsec[(*s)]);//xsec[(*s)]);
    tabXSec.setCellContent(int(i+1),2,wgt [(*s)]);//wgt [(*s)]);
  }

  tabXSec.saveAs("table_xSec.tex");
  tabXSec.print();
         
  //_____________________________________________________
  ICLatexTabular tQCDCompare_YieldAbsolute = get_tQCDCompare_YieldAbsolute(); // Initialization of absolute event yields table 
  ICLatexTabular tQCDCompare_YieldTrigWgt  = get_tQCDCompare_YieldTrigWgt();  // Initialization of trigger weighted eventd
  ICLatexTabular tQCDCompare_YieldXsecWgt  = get_tQCDCompare_YieldXsecWgt();  // Initialization of xsec weighted
 
  ICLatexTabular tQCDInc_YieldAbsolute     = get_tQCDInc_YieldAbsolute();
  ICLatexTabular tQCDInc_YieldTrigWgt      = get_tQCDInc_YieldTrigWgt();      // Initialization of merged table
  ICLatexTabular tQCDInc_YieldXsecWgt      = get_tQCDInc_YieldXsecWgt();  // Initialization of xsec weighted
  
  ICLatexTabular tabEvTotalWeighted        = get_tabEvTotalWeighted(); // Initialization of merged table
  ICLatexTabular tabEvAllTotalWeighted = get_tabEvAllTotalWeighted(); 
  
  //_________________________________________    
  for(unsigned i=0; i<cuts.size(); i++){

    MapString_ICH1F mPlots  = MapString_ICH1F(files,Form("%s/n_vtx",cuts[i].c_str()));

    // QCD Sample Compare: Filling table absolute counts 
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 0,cuts[i]);
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 1,mPlots["QCD-Pt-80to120"]     ->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 2,mPlots["QCD_VBF-Pt-80to120"] ->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 3,mPlots["QCD-Pt-120to170"]    ->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 4,mPlots["QCD_VBF-Pt-120to170"]->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 5,mPlots["QCD-Pt-170to300"]    ->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 6,mPlots["QCD_VBF-Pt-170to300"]->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 7,mPlots["QCD-Pt-300to470"]    ->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 8,mPlots["QCD_VBF-Pt-300to470"]->GetEntries());    
    tQCDCompare_YieldAbsolute.setCellContent(i+2, 9,mPlots["QCD-Pt-470to600"]    ->GetEntries());
    tQCDCompare_YieldAbsolute.setCellContent(i+2,10,mPlots["QCD_VBF-Pt-470to600"]->GetEntries());

    // QCD Sample Compare: Filling table weighted events (trigger, pu)
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 0,cuts[i]);
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 1,mPlots["QCD-Pt-80to120"]     ->Integral(0,mPlots["QCD-Pt-80to120"]     ->GetNbinsX()+1));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 2,mPlots["QCD_VBF-Pt-80to120"] ->Integral(0,mPlots["QCD_VBF-Pt-80to120"] ->GetNbinsX()+1));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 3,mPlots["QCD-Pt-120to170"]    ->Integral(0,mPlots["QCD-Pt-120to170"]    ->GetNbinsX()+1));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 4,mPlots["QCD_VBF-Pt-120to170"]->Integral(0,mPlots["QCD_VBF-Pt-120to170"]->GetNbinsX()+1));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 5,mPlots["QCD-Pt-170to300"]    ->Integral(0,mPlots["QCD-Pt-170to300"]    ->GetNbinsX()+1));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 6,mPlots["QCD_VBF-Pt-170to300"]->Integral(0,mPlots["QCD_VBF-Pt-170to300"]->GetNbinsX()+1));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 7,mPlots["QCD-Pt-300to470"]    ->Integral(0,mPlots["QCD-Pt-300to470"]    ->GetNbinsX()+1));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 8,mPlots["QCD_VBF-Pt-300to470"]->Integral(0,mPlots["QCD_VBF-Pt-300to470"]->GetNbinsX()+1));    
    tQCDCompare_YieldTrigWgt.setCellContent(i+2, 9,mPlots["QCD-Pt-470to600"]    ->Integral(0,mPlots["QCD-Pt-470to600"]    ->GetNbinsX()+1));
    tQCDCompare_YieldTrigWgt.setCellContent(i+2,10,mPlots["QCD_VBF-Pt-470to600"]->Integral(0,mPlots["QCD_VBF-Pt-470to600"]->GetNbinsX()+1));    
   
    // QCD Inclusive: Filling table absolute counts 
    tQCDInc_YieldAbsolute.setCellContent(i+1, 0,cuts[i]);
    tQCDInc_YieldAbsolute.setCellContent(i+1, 1,mPlots["QCD-Pt-30to50"]    ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 2,mPlots["QCD-Pt-50to80"]    ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 3,mPlots["QCD-Pt-80to120"]   ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 4,mPlots["QCD-Pt-120to170"]  ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 5,mPlots["QCD-Pt-170to300"]  ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 6,mPlots["QCD-Pt-300to470"]  ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 7,mPlots["QCD-Pt-470to600"]  ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 8,mPlots["QCD-Pt-600to800"]  ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1, 9,mPlots["QCD-Pt-800to1000"] ->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1,10,mPlots["QCD-Pt-1000to1400"]->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1,11,mPlots["QCD-Pt-1400to1800"]->GetEntries());
    tQCDInc_YieldAbsolute.setCellContent(i+1,12,mPlots["QCD-Pt-1800"]      ->GetEntries());

    // QCD Inclusive: Filling table weighted events (trigger, pu) for All QCD Inclusive samples
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 0,cuts[i]);
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 1,mPlots["QCD-Pt-30to50"]    ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 2,mPlots["QCD-Pt-50to80"]    ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 3,mPlots["QCD-Pt-80to120"]   ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 4,mPlots["QCD-Pt-120to170"]  ->Integral(0,mPlots["QCD-Pt-120to170"]->GetNbinsX()+1));
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 5,mPlots["QCD-Pt-170to300"]  ->Integral(0,mPlots["QCD-Pt-170to300"]->GetNbinsX()+1));
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 6,mPlots["QCD-Pt-300to470"]  ->Integral(0,mPlots["QCD-Pt-300to470"]->GetNbinsX()+1));    
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 7,mPlots["QCD-Pt-470to600"]  ->Integral(0,mPlots["QCD-Pt-470to600"]->GetNbinsX()+1));
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 8,mPlots["QCD-Pt-600to800"]  ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tQCDInc_YieldTrigWgt.setCellContent(i+1, 9,mPlots["QCD-Pt-800to1000"] ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tQCDInc_YieldTrigWgt.setCellContent(i+1,10,mPlots["QCD-Pt-1000to1400"]->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tQCDInc_YieldTrigWgt.setCellContent(i+1,11,mPlots["QCD-Pt-1400to1800"]->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tQCDInc_YieldTrigWgt.setCellContent(i+1,12,mPlots["QCD-Pt-1800"]      ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));

    // Putting in cross section normalization weights
    mPlots.Scale(wgt);

    // Filling table weighted events (trigger, pu and xsec)
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 0,cuts[i]);
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 1,mPlots["QCD-Pt-80to120"]     ->Integral(0,mPlots["QCD-Pt-80to120"]     ->GetNbinsX()+1));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 2,mPlots["QCD_VBF-Pt-80to120"] ->Integral(0,mPlots["QCD_VBF-Pt-80to120"] ->GetNbinsX()+1));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 3,mPlots["QCD-Pt-120to170"]    ->Integral(0,mPlots["QCD-Pt-120to170"]    ->GetNbinsX()+1));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 4,mPlots["QCD_VBF-Pt-120to170"]->Integral(0,mPlots["QCD_VBF-Pt-120to170"]->GetNbinsX()+1));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 5,mPlots["QCD-Pt-170to300"]    ->Integral(0,mPlots["QCD-Pt-170to300"]    ->GetNbinsX()+1));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 6,mPlots["QCD_VBF-Pt-170to300"]->Integral(0,mPlots["QCD_VBF-Pt-170to300"]->GetNbinsX()+1));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 7,mPlots["QCD-Pt-300to470"]    ->Integral(0,mPlots["QCD-Pt-300to470"]    ->GetNbinsX()+1));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 8,mPlots["QCD_VBF-Pt-300to470"]->Integral(0,mPlots["QCD_VBF-Pt-300to470"]->GetNbinsX()+1));    
    tQCDCompare_YieldXsecWgt.setCellContent(i+2, 9,mPlots["QCD-Pt-470to600"]    ->Integral(0,mPlots["QCD-Pt-470to600"]    ->GetNbinsX()+1));
    tQCDCompare_YieldXsecWgt.setCellContent(i+2,10,mPlots["QCD_VBF-Pt-470to600"]->Integral(0,mPlots["QCD_VBF-Pt-470to600"]->GetNbinsX()+1));    
    
    // QCD Inclusive: Filling table weighted events (trigger, pu and xsec)
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 0,cuts[i]);
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 1,mPlots["QCD-Pt-30to50"]    ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 2,mPlots["QCD-Pt-50to80"]    ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 3,mPlots["QCD-Pt-80to120"]   ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 4,mPlots["QCD-Pt-120to170"]  ->Integral(0,mPlots["QCD-Pt-120to170"]->GetNbinsX()+1));
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 5,mPlots["QCD-Pt-170to300"]  ->Integral(0,mPlots["QCD-Pt-170to300"]->GetNbinsX()+1));
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 6,mPlots["QCD-Pt-300to470"]  ->Integral(0,mPlots["QCD-Pt-300to470"]->GetNbinsX()+1));    
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 7,mPlots["QCD-Pt-470to600"]  ->Integral(0,mPlots["QCD-Pt-470to600"]->GetNbinsX()+1));
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 8,mPlots["QCD-Pt-600to800"]  ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tQCDInc_YieldXsecWgt.setCellContent(i+1, 9,mPlots["QCD-Pt-800to1000"] ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tQCDInc_YieldXsecWgt.setCellContent(i+1,10,mPlots["QCD-Pt-1000to1400"]->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tQCDInc_YieldXsecWgt.setCellContent(i+1,11,mPlots["QCD-Pt-1400to1800"]->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tQCDInc_YieldXsecWgt.setCellContent(i+1,12,mPlots["QCD-Pt-1800"]      ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));    
    
    // Merging samples and calculating integral    
    TH1F *hData   = mPlots.getMerged(Form("Data_%s_n_vtx",  cuts[i].c_str()),samples_data);
    TH1F *hQCDInc = mPlots.getMerged(Form("QCDInc_%s_n_vtx",cuts[i].c_str()),samplesQCDInc);
    TH1F *hQCDVBF = mPlots.getMerged(Form("QCDVBF_%s_n_vtx",cuts[i].c_str()),samplesQCDVBF);
    TH1F *hTTbar  = mPlots.getMerged(Form("TTBar_%s_n_vtx", cuts[i].c_str()),samples_ttbar);
    TH1F *hWjets  = mPlots.getMerged(Form("Wjets_%s_n_vtx", cuts[i].c_str()),samples_wjets);
    TH1F *hVV     = mPlots.getMerged(Form("VV_%s_n_vtx",    cuts[i].c_str()),samples_vv);
    TH1F *hGjets  = mPlots.getMerged(Form("Gjets_%s_n_vtx", cuts[i].c_str()),samples_gjets);
    TH1F *hEWK    = mPlots.getMerged(Form("EWK_%s_n_vtx",   cuts[i].c_str()),samples_ewk);
    TH1F *hZjets  = mPlots.getMerged(Form("Zjets_%s_n_vtx", cuts[i].c_str()),samples_zjets);
    TH1F *hDY     = mPlots.getMerged(Form("DY_%s_n_vtx",    cuts[i].c_str()),samples_dy);
    
    TH1F *hQCDIncAll = mPlots.getMerged(Form("QCDIncAll_%s_n_vtx",cuts[i].c_str()),samplesQCDIncAll);
    TH1F *hQCDVBFAll = mPlots.getMerged(Form("QCDVBFAll_%s_n_vtx",cuts[i].c_str()),samples_qcdvbfextra);
    
    tabEvTotalWeighted.setCellContent(i+1, 0,cuts[i]);
    tabEvTotalWeighted.setCellContent(i+1, 1,hData  ->Integral());
    tabEvTotalWeighted.setCellContent(i+1, 2,hQCDInc->Integral());
    tabEvTotalWeighted.setCellContent(i+1, 3,hQCDVBF->Integral());
    tabEvTotalWeighted.setCellContent(i+1, 4,hTTbar ->Integral());
    tabEvTotalWeighted.setCellContent(i+1, 5,hWjets ->Integral());
    tabEvTotalWeighted.setCellContent(i+1, 6,hVV    ->Integral());
    tabEvTotalWeighted.setCellContent(i+1, 7,hGjets ->Integral());
    tabEvTotalWeighted.setCellContent(i+1, 8,hEWK   ->Integral());
    tabEvTotalWeighted.setCellContent(i+1, 9,hZjets ->Integral());
    tabEvTotalWeighted.setCellContent(i+1,10,hDY    ->Integral());
    
    double mcTotal = hTTbar ->Integral()
                    +hWjets ->Integral()
		    +hVV    ->Integral()
                    +hGjets ->Integral()
                    +hEWK   ->Integral()
                    +hZjets ->Integral()
                    +hDY    ->Integral();
		    
		    
    tabEvAllTotalWeighted.setCellContent(i+1, 0,cuts[i]);
    tabEvAllTotalWeighted.setCellContent(i+1, 1,hQCDIncAll->Integral());
    tabEvAllTotalWeighted.setCellContent(i+1, 2,hQCDVBFAll->Integral());
    tabEvAllTotalWeighted.setCellContent(i+1, 3,hData     ->Integral());
		    
    tabEvAllTotalWeighted.setCellContent(i+1,11,mcTotal);
    
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
  }
  
  // Fixing the underscore
  tQCDCompare_YieldAbsolute.setCellContent(8, 0,"DPhiSIGNAL\\_CJVpass");
  tQCDCompare_YieldTrigWgt .setCellContent(8, 0,"DPhiSIGNAL\\_CJVpass");
  tQCDCompare_YieldXsecWgt .setCellContent(8, 0,"DPhiSIGNAL\\_CJVpass");
  tQCDInc_YieldAbsolute    .setCellContent(7, 0,"DPhiSIGNAL\\_CJVpass");
  tQCDInc_YieldTrigWgt     .setCellContent(7, 0,"DPhiSIGNAL\\_CJVpass");
  tQCDInc_YieldXsecWgt     .setCellContent(7, 0,"DPhiSIGNAL\\_CJVpass");

  tabEvTotalWeighted       .setCellContent(7, 0,"DPhiSIGNAL\\_CJVpass");
  tabEvAllTotalWeighted    .setCellContent(7, 0,"DPhiSIGNAL\\_CJVpass");

  tQCDCompare_YieldAbsolute.saveAs("tQCDCompare_YieldAbsolute.tex");
  tQCDCompare_YieldAbsolute.print();
  
  tQCDCompare_YieldTrigWgt.saveAs("tQCDCompare_YieldTrigWgt.tex");
  tQCDCompare_YieldTrigWgt.print();
  
  tQCDCompare_YieldXsecWgt.saveAs("tQCDCompare_YieldXsecWgt.tex");
  tQCDCompare_YieldXsecWgt.print();

  tQCDInc_YieldAbsolute.saveAs("tQCDInc_YieldAbsolute.tex");
  tQCDInc_YieldAbsolute.print();
  
  tQCDInc_YieldTrigWgt.saveAs("tQCDInc_YieldTrigWgt.tex");
  tQCDInc_YieldTrigWgt.print();
  
  tQCDInc_YieldXsecWgt.saveAs("tQCDInc_YieldXsecWgt.tex");
  tQCDInc_YieldXsecWgt.print();
  
  tabEvTotalWeighted.saveAs("table_EvTotalWeighted.tex");
  tabEvTotalWeighted.print();


  tabEvAllTotalWeighted.saveAs("table_EvAllTotalWeighted.tex");
  tabEvAllTotalWeighted.print();
  
}

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
ICLatexTabular get_tabEvTotalWeighted(){
  
  ICLatexTabular tabEvTotalWeighted(8,12);
  tabEvTotalWeighted.setTabularPrecision(".2");
  
  tabEvTotalWeighted.setTabularColumnDecoration("|");
  tabEvTotalWeighted.setColumnDecorationAfter  ( 0,"||");
  tabEvTotalWeighted.setColumnDecorationAfter  (10,"||");
  
  tabEvTotalWeighted.setRowDecorationBefore(0,"\\hline");
  tabEvTotalWeighted.setRowDecorationBefore(1,"\\hline \\hline");
  tabEvTotalWeighted.setRowDecorationAfter (7,"\\hline");
  
  tabEvTotalWeighted.setCellContent(0, 0,"Sample");
  tabEvTotalWeighted.setCellContent(0, 1,"Data");
  tabEvTotalWeighted.setCellContent(0, 2,"QCD Inc");
  tabEvTotalWeighted.setCellContent(0, 3,"QCD VBF");
  tabEvTotalWeighted.setCellContent(0, 4,"$t\\bar{t}$");
  tabEvTotalWeighted.setCellContent(0, 5,"W+Jets");
  tabEvTotalWeighted.setCellContent(0, 6,"VV");
  tabEvTotalWeighted.setCellContent(0, 7,"G+Jets");
  tabEvTotalWeighted.setCellContent(0, 8,"EWK V+2j");
  tabEvTotalWeighted.setCellContent(0, 9,"Z+Jets");
  tabEvTotalWeighted.setCellContent(0,10,"DY");
  tabEvTotalWeighted.setCellContent(0,11,"MC Total");
  
  return tabEvTotalWeighted;
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

//_____________________________________________________
ICLatexTabular get_tabEvAllTotalWeighted(){
  
  ICLatexTabular tabEvTotalWeighted(8,4);
  tabEvTotalWeighted.setTabularPrecision(".2");
  
  tabEvTotalWeighted.setTabularColumnDecoration("|");
  tabEvTotalWeighted.setColumnDecorationAfter  (0,"||");
  tabEvTotalWeighted.setColumnDecorationAfter  (2,"||");
  
  tabEvTotalWeighted.setRowDecorationBefore(0,"\\hline");
  tabEvTotalWeighted.setRowDecorationBefore(1,"\\hline \\hline");
  tabEvTotalWeighted.setRowDecorationAfter (7,"\\hline");
  
  tabEvTotalWeighted.setCellContent(0, 0,"Sample");
  tabEvTotalWeighted.setCellContent(0, 1,"QCD Inc");
  tabEvTotalWeighted.setCellContent(0, 2,"QCD VBF");
  tabEvTotalWeighted.setCellContent(0, 3,"Data");
  
  return tabEvTotalWeighted;
}