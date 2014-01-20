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

  double lumi = 19500.3;

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
  
  tabXSec.setCellContent(0,0,"Sample");
  tabXSec.setCellContent(0,1,"Cross Section [pb]");
  tabXSec.setCellContent(0,2,"Event Weight");
  
  cout << "N Samples: " << samples.size() << endl;
  for(unsigned i=0; i<samples.size(); i++){
    
    string* s = &(samples[i]);
    
    tabXSec.setCellContent(int(i+1),0,Form("\\verb|%s|",(*s).c_str()));//samples[i]);  
    tabXSec.setCellContent(int(i+1),1,xsec[(*s)]);//xsec[(*s)]);
    tabXSec.setCellContent(int(i+1),2,wgt [(*s)]);//wgt [(*s)]);
  }
    
  tabXSec.setColumnDecorationBefore(0,"|");
  tabXSec.setColumnDecorationAfter (2,"|");
  
  tabXSec.setRowDecorationBefore( 0,"\\hline");
  tabXSec.setRowDecorationBefore( 1,"\\hline \\hline");
  tabXSec.setRowDecorationAfter (17,"\\hline");
  
  tabXSec.saveAs("table_xSec.tex");
  tabXSec.print();
    
  //_________________________________________    
  vector< map<string,TH1F*>* > cuts;
  
  map<string,TH1F*> HLTMetClean_n_vtx;
  for(map<string,TFile*>::iterator f=files.begin(); f!=files.end(); f++){
    TH1F* h = (TH1F*) f->second->Get("HLTMetClean/n_vtx");
    HLTMetClean_n_vtx[f->first] = h; 
  }
  cuts.push_back(&HLTMetClean_n_vtx);
  
  map<string,TH1F*> JetPair_n_vtx;
  for(map<string,TFile*>::iterator f=files.begin(); f!=files.end(); f++){
    TH1F* h = (TH1F*) f->second->Get("JetPair/n_vtx");
    JetPair_n_vtx[f->first] = h; 
  }  
  cuts.push_back(&JetPair_n_vtx);
  
  map<string,TH1F*> DEta_n_vtx;
  for(map<string,TFile*>::iterator f=files.begin(); f!=files.end(); f++){
    TH1F* h = (TH1F*) f->second->Get("DEta/n_vtx");
    DEta_n_vtx[f->first] = h; 
  }  
  cuts.push_back(&DEta_n_vtx);
  
  map<string,TH1F*> MET_n_vtx;
  for(map<string,TFile*>::iterator f=files.begin(); f!=files.end(); f++){
    TH1F* h = (TH1F*) f->second->Get("MET/n_vtx");
    MET_n_vtx[f->first] = h; 
  }  
  cuts.push_back(&MET_n_vtx);
  
  map<string,TH1F*> TightMjj_n_vtx;
  for(map<string,TFile*>::iterator f=files.begin(); f!=files.end(); f++){
    TH1F* h = (TH1F*) f->second->Get("TightMjj/n_vtx");
    TightMjj_n_vtx[f->first] = h; 
  }  
  cuts.push_back(&TightMjj_n_vtx);
  
  map<string,TH1F*> CJVpass_n_vtx;
  for(map<string,TFile*>::iterator f=files.begin(); f!=files.end(); f++){
    TH1F* h = (TH1F*) f->second->Get("CJVpass/n_vtx");
    CJVpass_n_vtx[f->first] = h; 
  }  
  cuts.push_back(&CJVpass_n_vtx);
  
  map<string,TH1F*> DPhiSIGNAL_CJVpass_n_vtx;
  for(map<string,TFile*>::iterator f=files.begin(); f!=files.end(); f++){
    TH1F* h = (TH1F*) f->second->Get("DPhiSIGNAL_CJVpass/n_vtx");
    DPhiSIGNAL_CJVpass_n_vtx[f->first] = h; 
  }  
  cuts.push_back(&DPhiSIGNAL_CJVpass_n_vtx);
  
  //_________________________________________
  ICLatexTabular tabEvWeighted(9,11);
  tabEvWeighted.setTabularPrecision(".2");
  
  tabEvWeighted.setColumnDecorationBefore( 0,"|");
  tabEvWeighted.setColumnDecorationAfter ( 0,"|");
  tabEvWeighted.setColumnDecorationAfter ( 2,"|");
  tabEvWeighted.setColumnDecorationAfter ( 4,"|");
  tabEvWeighted.setColumnDecorationAfter ( 6,"|");
  tabEvWeighted.setColumnDecorationAfter ( 8,"|");
  tabEvWeighted.setColumnDecorationAfter (10,"|");
  
  tabEvWeighted.setRowDecorationBefore(0,"\\hline");
  tabEvWeighted.setRowDecorationBefore(1,"\\hline");
  tabEvWeighted.setRowDecorationBefore(2,"\\hline \\hline");
  tabEvWeighted.setRowDecorationAfter (8,"\\hline");
  
  tabEvWeighted.setCellContent(1, 0,"Sample");
  tabEvWeighted.setCellContent(0, 1, "80to120"); tabEvWeighted.setCellContent(1, 1,"Inc");
  tabEvWeighted.setCellContent(0, 2, "80to120"); tabEvWeighted.setCellContent(1, 2,"VBF");
  tabEvWeighted.setCellContent(0, 3,"120to170"); tabEvWeighted.setCellContent(1, 3,"Inc");
  tabEvWeighted.setCellContent(0, 4,"120to170"); tabEvWeighted.setCellContent(1, 4,"VBF");
  tabEvWeighted.setCellContent(0, 5,"170to300"); tabEvWeighted.setCellContent(1, 5,"Inc");
  tabEvWeighted.setCellContent(0, 6,"170to300"); tabEvWeighted.setCellContent(1, 6,"VBF");
  tabEvWeighted.setCellContent(0, 7,"300to470"); tabEvWeighted.setCellContent(1, 7,"Inc");
  tabEvWeighted.setCellContent(0, 8,"300to470"); tabEvWeighted.setCellContent(1, 8,"VBF");
  tabEvWeighted.setCellContent(0, 9,"470to600"); tabEvWeighted.setCellContent(1, 9,"Inc");
  tabEvWeighted.setCellContent(0,10,"470to600"); tabEvWeighted.setCellContent(1,10,"VBF");
  
  tabEvWeighted.setCellContent(2, 0,"HLTMetClean");
  tabEvWeighted.setCellContent(3, 0,"JetPair");  
  tabEvWeighted.setCellContent(4, 0,"DEta");
  tabEvWeighted.setCellContent(5, 0,"MET");
  tabEvWeighted.setCellContent(6, 0,"TightMjj");
  tabEvWeighted.setCellContent(7, 0,"CJVpass");
  tabEvWeighted.setCellContent(8, 0,"DPhiSIGNAL\\_CJVpass");
  
  //_________________________________________
  ICLatexTabular tabEvAbsolute(9,11);
  tabEvAbsolute.setTabularPrecision(".0");
  
  tabEvAbsolute.setColumnDecorationBefore( 0,"|");
  tabEvAbsolute.setColumnDecorationAfter ( 0,"|");
  tabEvAbsolute.setColumnDecorationAfter ( 2,"|");
  tabEvAbsolute.setColumnDecorationAfter ( 4,"|");
  tabEvAbsolute.setColumnDecorationAfter ( 6,"|");
  tabEvAbsolute.setColumnDecorationAfter ( 8,"|");
  tabEvAbsolute.setColumnDecorationAfter (10,"|");
  
  tabEvAbsolute.setRowDecorationBefore(0,"\\hline");
  tabEvAbsolute.setRowDecorationBefore(1,"\\hline");
  tabEvAbsolute.setRowDecorationBefore(2,"\\hline \\hline");
  tabEvAbsolute.setRowDecorationAfter (8,"\\hline");
  
  tabEvAbsolute.setCellContent(1, 0,"Sample");
  tabEvAbsolute.setCellContent(0, 1, "80to120"); tabEvAbsolute.setCellContent(1, 1,"Inc");
  tabEvAbsolute.setCellContent(0, 2, "80to120"); tabEvAbsolute.setCellContent(1, 2,"VBF");
  tabEvAbsolute.setCellContent(0, 3,"120to170"); tabEvAbsolute.setCellContent(1, 3,"Inc");
  tabEvAbsolute.setCellContent(0, 4,"120to170"); tabEvAbsolute.setCellContent(1, 4,"VBF");
  tabEvAbsolute.setCellContent(0, 5,"170to300"); tabEvAbsolute.setCellContent(1, 5,"Inc");
  tabEvAbsolute.setCellContent(0, 6,"170to300"); tabEvAbsolute.setCellContent(1, 6,"VBF");
  tabEvAbsolute.setCellContent(0, 7,"300to470"); tabEvAbsolute.setCellContent(1, 7,"Inc");
  tabEvAbsolute.setCellContent(0, 8,"300to470"); tabEvAbsolute.setCellContent(1, 8,"VBF");
  tabEvAbsolute.setCellContent(0, 9,"470to600"); tabEvAbsolute.setCellContent(1, 9,"Inc");
  tabEvAbsolute.setCellContent(0,10,"470to600"); tabEvAbsolute.setCellContent(1,10,"VBF");
  
  tabEvAbsolute.setCellContent(2, 0,"HLTMetClean");
  tabEvAbsolute.setCellContent(3, 0,"JetPair");  
  tabEvAbsolute.setCellContent(4, 0,"DEta");
  tabEvAbsolute.setCellContent(5, 0,"MET");
  tabEvAbsolute.setCellContent(6, 0,"TightMjj");
  tabEvAbsolute.setCellContent(7, 0,"CJVpass");
  tabEvAbsolute.setCellContent(8, 0,"DPhiSIGNAL\\_CJVpass");
  
  
  // Applying weights
  for(unsigned i=0; i<cuts.size(); i++){
    
    map<string,TH1F*>* plots = cuts[i];
    TH1F* h;
    
    h = (*plots)["QCD-Pt-80to120"];  
    tabEvAbsolute.setCellContent(i+2,1,h->GetEntries());
    h->Scale(wgt["QCD-Pt-80to120"]);  
    tabEvWeighted.setCellContent(i+2,1,h->Integral(0,h->GetNbinsX()+1));
    
    h = (*plots)["QCD-Pt-120to170"]; 
    tabEvAbsolute.setCellContent(i+2,3,h->GetEntries());
    h->Scale(wgt["QCD-Pt-120to170"]); 
    tabEvWeighted.setCellContent(i+2,3,h->Integral(0,h->GetNbinsX()+1));
    
    h = (*plots)["QCD-Pt-170to300"]; 
    tabEvAbsolute.setCellContent(i+2,5,h->GetEntries());
    h->Scale(wgt["QCD-Pt-170to300"]); 
    tabEvWeighted.setCellContent(i+2,5,h->Integral(0,h->GetNbinsX()+1));
    
    h = (*plots)["QCD-Pt-300to470"]; 
    tabEvAbsolute.setCellContent(i+2,7,h->GetEntries());
    h->Scale(wgt["QCD-Pt-300to470"]); 
    tabEvWeighted.setCellContent(i+2,7,h->Integral(0,h->GetNbinsX()+1));
    
    h = (*plots)["QCD-Pt-470to600"]; 
    tabEvAbsolute.setCellContent(i+2,9,h->GetEntries());
    h->Scale(wgt["QCD-Pt-470to600"]); 
    tabEvWeighted.setCellContent(i+2,9,h->Integral(0,h->GetNbinsX()+1));
    
    
    
    h = (*plots)["QCD_VBF-Pt-80to120"];
    tabEvAbsolute.setCellContent(i+2,2,h->GetEntries());
    h->Scale(wgt["QCD_VBF-Pt-80to120"]);  
    tabEvWeighted.setCellContent(i+2, 2,h->Integral(0,h->GetNbinsX()+1));
    
    h = (*plots)["QCD_VBF-Pt-120to170"];
    tabEvAbsolute.setCellContent(i+2,4,h->GetEntries());
    h->Scale(wgt["QCD_VBF-Pt-120to170"]); 
    tabEvWeighted.setCellContent(i+2, 4,h->Integral(0,h->GetNbinsX()+1));
    
    h = (*plots)["QCD_VBF-Pt-170to300"]; 
    tabEvAbsolute.setCellContent(i+2,6,h->GetEntries());
    h->Scale(wgt["QCD_VBF-Pt-170to300"]); 
    tabEvWeighted.setCellContent(i+2, 6,h->Integral(0,h->GetNbinsX()+1));
    
    h = (*plots)["QCD_VBF-Pt-300to470"]; 
    tabEvAbsolute.setCellContent(i+2,8,h->GetEntries());
    h->Scale(wgt["QCD_VBF-Pt-300to470"]); 
    tabEvWeighted.setCellContent(i+2, 8,h->Integral(0,h->GetNbinsX()+1));
    
    h = (*plots)["QCD_VBF-Pt-470to600"];
    tabEvAbsolute.setCellContent(i+2,10,h->GetEntries());
    h->Scale(wgt["QCD_VBF-Pt-470to600"]); 
    tabEvWeighted.setCellContent(i+2,10,h->Integral(0,h->GetNbinsX()+1));   
    
  }
  
  tabEvWeighted.saveAs("table_EvWeighted.tex");
  tabEvWeighted.print();

  tabEvAbsolute.saveAs("table_EvAbsolute.tex");
  tabEvWeighted.print();
  
  // 
  for(unsigned i=0; i<cuts.size(); i++){
  
    map<string,TH1F*>* plots = cuts[i];
    
    TH1F* QCDInc = (TH1F*) (*plots)["QCD-Pt-80to120"]->Clone("QCDInc");
    QCDInc->Add((*plots)["QCD-Pt-120to170"]);
    QCDInc->Add((*plots)["QCD-Pt-170to300"]);
    QCDInc->Add((*plots)["QCD-Pt-300to470"]);
    QCDInc->Add((*plots)["QCD-Pt-470to600"]);

    
    TH1F* QCDVBF = (TH1F*) (*plots)["QCD_VBF-Pt-80to120"]->Clone("QCDVBF");
    QCDVBF->Add((*plots)["QCD_VBF-Pt-120to170"]);
    QCDVBF->Add((*plots)["QCD_VBF-Pt-170to300"]);
    QCDVBF->Add((*plots)["QCD_VBF-Pt-300to470"]);
    QCDVBF->Add((*plots)["QCD_VBF-Pt-470to600"]);    

    QCDInc->Integral(0,QCDInc->GetNbinsX()+1);    
    double intQCDInc = QCDInc->Integral(0,QCDInc->GetNbinsX()+1);
    
    QCDVBF->Integral(0,QCDVBF->GetNbinsX()+1);
    double intQCDVBF = QCDVBF->Integral(0,QCDVBF->GetNbinsX()+1);

    printf("QCD Inc: %15.2f   QCD VBF : %15.2f\n",intQCDInc,intQCDVBF);        
    
  }
  
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