// TODO: Description

// ICTools includes
#include "Latex/Table/interface/ICLatexTable.h"
#include "Latex/Table/interface/ICLatexTabular.h"
#include "Latex/Table/interface/ICLatexCaption.h"

// ROOT includes
#include "TFile.h"
#include "TH1F.h"

// Standard libraries includes
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[]){

  double lumi = 19000;

  //_________________________________________
  map<string,TFile*> files;
  files["QCD-Pt-30to50"]     = new TFile("MC_QCD-Pt-30to50-pythia6.root");
  files["QCD-Pt-50to80"]     = new TFile("MC_QCD-Pt-50to80-pythia6.root");
  files["QCD-Pt-80to120"]    = new TFile("MC_QCD-Pt-80to120-pythia6.root");
  files["QCD-Pt-120to170"]   = new TFile("MC_QCD-Pt-120to170-pythia6.root");
  files["QCD-Pt-170to300"]   = new TFile("MC_QCD-Pt-170to300-pythia6.root");
  files["QCD-Pt-300to470"]   = new TFile("MC_QCD-Pt-300to470-pythia6.root");
  files["QCD-Pt-470to600"]   = new TFile("MC_QCD-Pt-470to600-pythia6.root");
  files["QCD-Pt-600to800"]   = new TFile("MC_QCD-Pt-600to800-pythia6.root");
  files["QCD-Pt-800to1000"]  = new TFile("MC_QCD-Pt-800to1000-pythia6.root");  
  files["QCD-Pt-1000to1400"] = new TFile("MC_QCD-Pt-1000to1400-pythia6.root");  
  files["QCD-Pt-1400to1800"] = new TFile("MC_QCD-Pt-1400to1800-pythia6.root");
  files["QCD-Pt-1800"]       = new TFile("MC_QCD-Pt-1800-pythia6.root");  

  files["QCD_VBF-Pt-80to120"]  = new TFile("MC_QCD-Pt-80to120_VBF-MET40.root");
  files["QCD_VBF-Pt-120to170"] = new TFile("MC_QCD-Pt-120to170_VBF-MET40.root");
  files["QCD_VBF-Pt-170to300"] = new TFile("MC_QCD-Pt-170to300_VBF-MET40.root");
  files["QCD_VBF-Pt-300to470"] = new TFile("MC_QCD-Pt-300to470_VBF-MET40.root");
  files["QCD_VBF-Pt-470to600"] = new TFile("MC_QCD-Pt-470to600_VBF-MET40.root");

  //_________________________________________
  map<string,double> xsec;
  xsec["QCD-Pt-30to50"]     = 66285328;
  xsec["QCD-Pt-50to80"]     =  8148778.0;
  xsec["QCD-Pt-80to120"]    =  1033680.0;
  xsec["QCD-Pt-120to170"]   =   156293.3;
  xsec["QCD-Pt-170to300"]   =    34138.15;
  xsec["QCD-Pt-300to470"]   =     1759.549;
  xsec["QCD-Pt-470to600"]   =      113.8791;
  xsec["QCD-Pt-600to800"]   =       26.9921;
  xsec["QCD-Pt-800to1000"]  =        3.550036;
  xsec["QCD-Pt-1000to1400"] =        0.737844;
  xsec["QCD-Pt-1400to1800"] =        0.03352235;
  xsec["QCD-Pt-1800"]       =        0.001829005;

  //_________________________________________
  map<string,double> evQCDInc;  
  evQCDInc["QCD-Pt-30to50"]     = 5910000.0;
  evQCDInc["QCD-Pt-50to80"]     = 5998860.0;
  evQCDInc["QCD-Pt-80to120"]    = 5994864.0;
  evQCDInc["QCD-Pt-120to170"]   = 5955732.0;
  evQCDInc["QCD-Pt-170to300"]   = 5814398.0;
  evQCDInc["QCD-Pt-300to470"]   = 5978500.0;
  evQCDInc["QCD-Pt-470to600"]   = 3964848.0;
  evQCDInc["QCD-Pt-600to800"]   = 3996864.0;
  evQCDInc["QCD-Pt-800to1000"]  = 3998563.0;
  evQCDInc["QCD-Pt-1000to1400"] = 1904088.0;
  evQCDInc["QCD-Pt-1400to1800"] = 1910062.0;
  evQCDInc["QCD-Pt-1800"]       = 947586.0;
    
  map<string,double> evQCDVBF;  
  evQCDVBF["QCD-Pt-80to120"]  = 39376000000;
  evQCDVBF["QCD-Pt-120to170"] = 7000000000;
  evQCDVBF["QCD-Pt-170to300"] = 1375000000;
  evQCDVBF["QCD-Pt-300to470"] = 80000000;
  evQCDVBF["QCD-Pt-470to600"] = 25000000;

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
  wgt["QCD-Pt-30to50"]       = (lumi*xsec["QCD-Pt-30to50"])    /evQCDInc["QCD-Pt-30to50"]    ;
  wgt["QCD-Pt-50to80"]       = (lumi*xsec["QCD-Pt-50to80"])    /evQCDInc["QCD-Pt-50to80"]    ;
  wgt["QCD-Pt-80to120"]      = (lumi*xsec["QCD-Pt-80to120"])   /evQCDInc["QCD-Pt-80to120"]   ;
  wgt["QCD-Pt-120to170"]     = (lumi*xsec["QCD-Pt-120to170"])  /evQCDInc["QCD-Pt-120to170"]  ;
  wgt["QCD-Pt-170to300"]     = (lumi*xsec["QCD-Pt-170to300"])  /evQCDInc["QCD-Pt-170to300"]  ;
  wgt["QCD-Pt-300to470"]     = (lumi*xsec["QCD-Pt-300to470"])  /evQCDInc["QCD-Pt-300to470"]  ;
  wgt["QCD-Pt-470to600"]     = (lumi*xsec["QCD-Pt-470to600"])  /evQCDInc["QCD-Pt-470to600"]  ;
  wgt["QCD-Pt-600to800"]     = (lumi*xsec["QCD-Pt-600to800"])  /evQCDInc["QCD-Pt-600to800"]  ;
  wgt["QCD-Pt-800to1000"]    = (lumi*xsec["QCD-Pt-800to1000"]) /evQCDInc["QCD-Pt-800to1000"] ;
  wgt["QCD-Pt-1000to1400"]   = (lumi*xsec["QCD-Pt-1000to1400"])/evQCDInc["QCD-Pt-1000to1400"];
  wgt["QCD-Pt-1400to1800"]   = (lumi*xsec["QCD-Pt-1400to1800"])/evQCDInc["QCD-Pt-1400to1800"];
  wgt["QCD-Pt-1800"]         = (lumi*xsec["QCD-Pt-1800"])      /evQCDInc["QCD-Pt-1800"]      ;
  wgt["QCD_VBF-Pt-80to120"]  = (lumi*xsec["QCD-Pt-80to120"])   /evQCDVBF["QCD-Pt-80to120"]   ;
  wgt["QCD_VBF-Pt-120to170"] = (lumi*xsec["QCD-Pt-120to170"])  /evQCDVBF["QCD-Pt-120to170"]  ;
  wgt["QCD_VBF-Pt-170to300"] = (lumi*xsec["QCD-Pt-170to300"])  /evQCDVBF["QCD-Pt-170to300"]  ;
  wgt["QCD_VBF-Pt-300to470"] = (lumi*xsec["QCD-Pt-300to470"])  /evQCDVBF["QCD-Pt-300to470"]  ;
  wgt["QCD_VBF-Pt-470to600"] = (lumi*xsec["QCD-Pt-470to600"])  /evQCDVBF["QCD-Pt-470to600"]  ;
  
  //_________________________________________  
  ICLatexTabular tabXSec(18,3);
  
  tabXSec.set(0,0,"Sample");
  tabXSec.set(0,1,"Cross Section [pb]");
  tabXSec.set(0,2,"Event Weight");
  
  cout << "N Samples: " << samples.size() << endl;
  for(unsigned i=0; i<samples.size(); i++){
    
    string* s = &(samples[i]);
    
    tabXSec.set(int(i+1),0,(*s));//samples[i]);  
    tabXSec.set(int(i+1),1,xsec[(*s)]);//xsec[(*s)]);
    tabXSec.set(int(i+1),2,wgt [(*s)]);//wgt [(*s)]);
  }
    
  tabXSec.setColumnDecorationBefore(0,"|");
  tabXSec.setColumnDecorationAfter (2,"|");
  
  tabXSec.setRowDecorationBefore( 0,"\\hline");
  tabXSec.setRowDecorationBefore( 1,"\\hline \\hline");
  tabXSec.setRowDecorationAfter (17,"\\hline");
  
  tabXSec.saveAs("table_xSec.tex");
  
  //_________________________________________
  cout << "Weights" << endl;
  for(unsigned i=0; i<samples.size() ; i++){
    
    string s = samples[i];
    double w = wgt[s];
    
    printf("%20s : %10.4f\n",s.c_str(),w);
  }
  cout<<endl;
    
  //_________________________________________    
  map<string,TH1F*> JetPair_n_vtx;
  for(map<string,TFile*>::iterator f=files.begin(); f!=files.end(); f++){
    
    TH1F* h = (TH1F*) f->second->Get("JetPair/n_vtx");
    
    JetPair_n_vtx[f->first] = h;
    
  }
  cout<<endl;  

  //_________________________________________  
  cout << "Entries" << endl;
  for(unsigned i=0; i<samples.size() ; i++){
    
    string s=samples[i];
    TH1F* h = JetPair_n_vtx[s];

    double entries  = h->GetEntries();
    double integral = h->Integral(0,h->GetNbinsX()+1);
    double intWgt   = integral*wgt[s];
    
    printf("%20s : %8.0f : %10.2f : %10.2f\n",s.c_str(),entries,integral,intWgt);    
  } 

  return 0;

}