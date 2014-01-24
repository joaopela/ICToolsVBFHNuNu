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
ICLatexTabular get_tabEvAbsolute();
ICLatexTabular get_tabEvTrig();
ICLatexTabular get_tabEvWeighted();
ICLatexTabular get_tabEvTotalWeighted();

ICLatexTabular get_tabEvAllTrig();
ICLatexTabular get_tabEvAllTotalWeighted();

int main(int argc, char *argv[]){

  double lumi = 19500.3;

  //_________________________________________
  map<string,TFile*> files;
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
  wgt["QCD-Pt-30to50"]       = (lumi*xsec["QCD-Pt-30to50"])    /events["QCD-Pt-30to50"];
  wgt["QCD-Pt-50to80"]       = (lumi*xsec["QCD-Pt-50to80"])    /events["QCD-Pt-50to80"];
  wgt["QCD-Pt-80to120"]      = (lumi*xsec["QCD-Pt-80to120"])   /events["QCD-Pt-80to120"];
  wgt["QCD-Pt-120to170"]     = (lumi*xsec["QCD-Pt-120to170"])  /events["QCD-Pt-120to170"];
  wgt["QCD-Pt-170to300"]     = (lumi*xsec["QCD-Pt-170to300"])  /events["QCD-Pt-170to300"];
  wgt["QCD-Pt-300to470"]     = (lumi*xsec["QCD-Pt-300to470"])  /events["QCD-Pt-300to470"];
  wgt["QCD-Pt-470to600"]     = (lumi*xsec["QCD-Pt-470to600"])  /events["QCD-Pt-470to600"];
  wgt["QCD-Pt-600to800"]     = (lumi*xsec["QCD-Pt-600to800"])  /events["QCD-Pt-600to800"];
  wgt["QCD-Pt-800to1000"]    = (lumi*xsec["QCD-Pt-800to1000"]) /events["QCD-Pt-800to1000"];
  wgt["QCD-Pt-1000to1400"]   = (lumi*xsec["QCD-Pt-1000to1400"])/events["QCD-Pt-1000to1400"];
  wgt["QCD-Pt-1400to1800"]   = (lumi*xsec["QCD-Pt-1400to1800"])/events["QCD-Pt-1400to1800"];
  wgt["QCD-Pt-1800"]         = (lumi*xsec["QCD-Pt-1800"])      /events["QCD-Pt-1800"];
  wgt["QCD_VBF-Pt-80to120"]  = (lumi*xsec["QCD-Pt-80to120"])   /events["QCD_VBF-Pt-80to120"];
  wgt["QCD_VBF-Pt-120to170"] = (lumi*xsec["QCD-Pt-120to170"])  /events["QCD_VBF-Pt-120to170"];
  wgt["QCD_VBF-Pt-170to300"] = (lumi*xsec["QCD-Pt-170to300"])  /events["QCD_VBF-Pt-170to300"];
  wgt["QCD_VBF-Pt-300to470"] = (lumi*xsec["QCD-Pt-300to470"])  /events["QCD_VBF-Pt-300to470"];
  wgt["QCD_VBF-Pt-470to600"] = (lumi*xsec["QCD-Pt-470to600"])  /events["QCD_VBF-Pt-470to600"];

  //_________________________________________    
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
  
  //_________________________________________  
  ICLatexTabular tabXSec = get_tabXSec();
  
  cout << "N Samples: " << samples.size() << endl;
  for(unsigned i=0; i<samples.size(); i++){
    
    string* s = &(samples[i]);
    
    tabXSec.setCellContent(int(i+1),0,Form("\\verb|%s|",(*s).c_str()));//samples[i]);  
    tabXSec.setCellContent(int(i+1),1,xsec[(*s)]);//xsec[(*s)]);
    tabXSec.setCellContent(int(i+1),2,wgt [(*s)]);//wgt [(*s)]);
  }

  tabXSec.saveAs("table_xSec.tex");
  tabXSec.print();
         
  //_____________________________________________________
  ICLatexTabular tabEvAbsolute      = get_tabEvAbsolute();      // Initialization of absolute event yields table 
  ICLatexTabular tabEvTrig          = get_tabEvTrig();          // Initialization of trigger weighted eventd
  ICLatexTabular tabEvWeighted      = get_tabEvWeighted();      // Initialization of weighted event yields table
  ICLatexTabular tabEvTotalWeighted = get_tabEvTotalWeighted(); // Initialization of merged table
 
  ICLatexTabular tabEvAllTrig          = get_tabEvAllTrig(); // Initialization of merged table
  ICLatexTabular tabEvAllTotalWeighted = get_tabEvAllTotalWeighted(); 
  
  //_________________________________________    
  for(unsigned i=0; i<cuts.size(); i++){

    MapString_ICH1F mPlots  = MapString_ICH1F(files,Form("%s/n_vtx",cuts[i].c_str()));

    // Filling table absolute counts
    tabEvAbsolute.setCellContent(i+2, 0,cuts[i]);
    tabEvAbsolute.setCellContent(i+2, 1,mPlots["QCD-Pt-80to120"]     ->GetEntries());
    tabEvAbsolute.setCellContent(i+2, 2,mPlots["QCD_VBF-Pt-80to120"] ->GetEntries());
    tabEvAbsolute.setCellContent(i+2, 3,mPlots["QCD-Pt-120to170"]    ->GetEntries());
    tabEvAbsolute.setCellContent(i+2, 4,mPlots["QCD_VBF-Pt-120to170"]->GetEntries());
    tabEvAbsolute.setCellContent(i+2, 5,mPlots["QCD-Pt-170to300"]    ->GetEntries());
    tabEvAbsolute.setCellContent(i+2, 6,mPlots["QCD_VBF-Pt-170to300"]->GetEntries());
    tabEvAbsolute.setCellContent(i+2, 7,mPlots["QCD-Pt-300to470"]    ->GetEntries());
    tabEvAbsolute.setCellContent(i+2, 8,mPlots["QCD_VBF-Pt-300to470"]->GetEntries());    
    tabEvAbsolute.setCellContent(i+2, 9,mPlots["QCD-Pt-470to600"]    ->GetEntries());
    tabEvAbsolute.setCellContent(i+2,10,mPlots["QCD_VBF-Pt-470to600"]->GetEntries());

    // Filling table weighted events (trigger, pu)
    tabEvTrig.setCellContent(i+2, 0,cuts[i]);
    tabEvTrig.setCellContent(i+2, 1,mPlots["QCD-Pt-80to120"]     ->Integral(0,mPlots["QCD-Pt-80to120"]     ->GetNbinsX()+1));
    tabEvTrig.setCellContent(i+2, 2,mPlots["QCD_VBF-Pt-80to120"] ->Integral(0,mPlots["QCD_VBF-Pt-80to120"] ->GetNbinsX()+1));
    tabEvTrig.setCellContent(i+2, 3,mPlots["QCD-Pt-120to170"]    ->Integral(0,mPlots["QCD-Pt-120to170"]    ->GetNbinsX()+1));
    tabEvTrig.setCellContent(i+2, 4,mPlots["QCD_VBF-Pt-120to170"]->Integral(0,mPlots["QCD_VBF-Pt-120to170"]->GetNbinsX()+1));
    tabEvTrig.setCellContent(i+2, 5,mPlots["QCD-Pt-170to300"]    ->Integral(0,mPlots["QCD-Pt-170to300"]    ->GetNbinsX()+1));
    tabEvTrig.setCellContent(i+2, 6,mPlots["QCD_VBF-Pt-170to300"]->Integral(0,mPlots["QCD_VBF-Pt-170to300"]->GetNbinsX()+1));
    tabEvTrig.setCellContent(i+2, 7,mPlots["QCD-Pt-300to470"]    ->Integral(0,mPlots["QCD-Pt-300to470"]    ->GetNbinsX()+1));
    tabEvTrig.setCellContent(i+2, 8,mPlots["QCD_VBF-Pt-300to470"]->Integral(0,mPlots["QCD_VBF-Pt-300to470"]->GetNbinsX()+1));    
    tabEvTrig.setCellContent(i+2, 9,mPlots["QCD-Pt-470to600"]    ->Integral(0,mPlots["QCD-Pt-470to600"]    ->GetNbinsX()+1));
    tabEvTrig.setCellContent(i+2,10,mPlots["QCD_VBF-Pt-470to600"]->Integral(0,mPlots["QCD_VBF-Pt-470to600"]->GetNbinsX()+1));    
   
    // Filling table weighted events (trigger, pu) for All QCD Inclusive samples
    tabEvAllTrig.setCellContent(i+1, 0,cuts[i]);
    tabEvAllTrig.setCellContent(i+1, 1,mPlots["QCD-Pt-30to50"]    ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tabEvAllTrig.setCellContent(i+1, 2,mPlots["QCD-Pt-50to80"]    ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tabEvAllTrig.setCellContent(i+1, 3,mPlots["QCD-Pt-80to120"]   ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tabEvAllTrig.setCellContent(i+1, 4,mPlots["QCD-Pt-120to170"]  ->Integral(0,mPlots["QCD-Pt-120to170"]->GetNbinsX()+1));
    tabEvAllTrig.setCellContent(i+1, 5,mPlots["QCD-Pt-170to300"]  ->Integral(0,mPlots["QCD-Pt-170to300"]->GetNbinsX()+1));
    tabEvAllTrig.setCellContent(i+1, 6,mPlots["QCD-Pt-300to470"]  ->Integral(0,mPlots["QCD-Pt-300to470"]->GetNbinsX()+1));    
    tabEvAllTrig.setCellContent(i+1, 7,mPlots["QCD-Pt-470to600"]  ->Integral(0,mPlots["QCD-Pt-470to600"]->GetNbinsX()+1));
    tabEvAllTrig.setCellContent(i+1, 8,mPlots["QCD-Pt-600to800"]  ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tabEvAllTrig.setCellContent(i+1, 9,mPlots["QCD-Pt-800to1000"] ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tabEvAllTrig.setCellContent(i+1,10,mPlots["QCD-Pt-1000to1400"]->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tabEvAllTrig.setCellContent(i+1,11,mPlots["QCD-Pt-1400to1800"]->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));
    tabEvAllTrig.setCellContent(i+1,12,mPlots["QCD-Pt-1800"]      ->Integral(0,mPlots["QCD-Pt-80to120"] ->GetNbinsX()+1));

    // Putting in normalization weights
    mPlots.Scale(wgt);

    TH1F *hIncAll = mPlots.getMerged(Form("QCDIncAll_%s_n_vtx",cuts[i].c_str()),samplesQCDIncAll);
    double intQCDIncAll = hIncAll->Integral(0,hIncAll->GetNbinsX()+1);
   
    tabEvAllTotalWeighted.setCellContent(i+1,0,cuts[i]);
    tabEvAllTotalWeighted.setCellContent(i+1,1,intQCDIncAll);
    
    delete hIncAll;

    // Filling table weighted events (trigger, pu and xsec)    
    tabEvWeighted.setCellContent(i+2, 0,cuts[i]);
    tabEvWeighted.setCellContent(i+2, 1,mPlots["QCD-Pt-80to120"]     ->Integral(0,mPlots["QCD-Pt-80to120"]     ->GetNbinsX()+1));
    tabEvWeighted.setCellContent(i+2, 2,mPlots["QCD_VBF-Pt-80to120"] ->Integral(0,mPlots["QCD_VBF-Pt-80to120"] ->GetNbinsX()+1));
    tabEvWeighted.setCellContent(i+2, 3,mPlots["QCD-Pt-120to170"]    ->Integral(0,mPlots["QCD-Pt-120to170"]    ->GetNbinsX()+1));
    tabEvWeighted.setCellContent(i+2, 4,mPlots["QCD_VBF-Pt-120to170"]->Integral(0,mPlots["QCD_VBF-Pt-120to170"]->GetNbinsX()+1));
    tabEvWeighted.setCellContent(i+2, 5,mPlots["QCD-Pt-170to300"]    ->Integral(0,mPlots["QCD-Pt-170to300"]    ->GetNbinsX()+1));
    tabEvWeighted.setCellContent(i+2, 6,mPlots["QCD_VBF-Pt-170to300"]->Integral(0,mPlots["QCD_VBF-Pt-170to300"]->GetNbinsX()+1));
    tabEvWeighted.setCellContent(i+2, 7,mPlots["QCD-Pt-300to470"]    ->Integral(0,mPlots["QCD-Pt-300to470"]    ->GetNbinsX()+1));
    tabEvWeighted.setCellContent(i+2, 8,mPlots["QCD_VBF-Pt-300to470"]->Integral(0,mPlots["QCD_VBF-Pt-300to470"]->GetNbinsX()+1));    
    tabEvWeighted.setCellContent(i+2, 9,mPlots["QCD-Pt-470to600"]    ->Integral(0,mPlots["QCD-Pt-470to600"]    ->GetNbinsX()+1));
    tabEvWeighted.setCellContent(i+2,10,mPlots["QCD_VBF-Pt-470to600"]->Integral(0,mPlots["QCD_VBF-Pt-470to600"]->GetNbinsX()+1));    
    
    TH1F *hInc    = mPlots.getMerged(Form("QCDInc_%s_n_vtx",   cuts[i].c_str()),samplesQCDInc);
    TH1F *hVBF    = mPlots.getMerged(Form("QCDVBF_%s_n_vtx",   cuts[i].c_str()),samplesQCDVBF);
    
    double intQCDInc    = hInc   ->Integral(0,hInc->GetNbinsX()+1);
    double intQCDVBF    = hVBF   ->Integral(0,hVBF->GetNbinsX()+1);
    
    tabEvTotalWeighted.setCellContent(i+1,0,cuts[i]);
    tabEvTotalWeighted.setCellContent(i+1,1,intQCDInc);
    tabEvTotalWeighted.setCellContent(i+1,2,intQCDVBF);
    
    delete hInc;
    delete hVBF;
  }
  
  // Fixing the underscore
  tabEvAbsolute        .setCellContent(8, 0,"DPhiSIGNAL\\_CJVpass");
  tabEvTrig            .setCellContent(8, 0,"DPhiSIGNAL\\_CJVpass");
  tabEvWeighted        .setCellContent(8, 0,"DPhiSIGNAL\\_CJVpass");
  tabEvTotalWeighted   .setCellContent(7, 0,"DPhiSIGNAL\\_CJVpass");
  tabEvAllTrig         .setCellContent(7, 0,"DPhiSIGNAL\\_CJVpass");
  tabEvAllTotalWeighted.setCellContent(7, 0,"DPhiSIGNAL\\_CJVpass");

  tabEvWeighted.saveAs("table_EvWeighted.tex");
  tabEvWeighted.print();

  tabEvTrig.saveAs("table_EvTrig.tex");
  tabEvTrig.print();
  
  tabEvAbsolute.saveAs("table_EvAbsolute.tex");
  tabEvWeighted.print();
  
  tabEvTotalWeighted.saveAs("table_EvTotalWeighted.tex");
  tabEvTotalWeighted.print();

  tabEvAllTrig.saveAs("table_EvAllTrig.tex");
  tabEvAllTrig.print();

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
ICLatexTabular get_tabEvAbsolute(){

  ICLatexTabular tabEvAbsolute(9,11);
  tabEvAbsolute.setTabularPrecision(".0");
  
  tabEvAbsolute.setColumnDecorationBefore( 0,"|");
  tabEvAbsolute.setColumnDecorationAfter ( 0,"||");
  tabEvAbsolute.setColumnDecorationAfter ( 2,"||");
  tabEvAbsolute.setColumnDecorationAfter ( 4,"||");
  tabEvAbsolute.setColumnDecorationAfter ( 6,"||");
  tabEvAbsolute.setColumnDecorationAfter ( 8,"||");
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
 
  return tabEvAbsolute;
}

//_____________________________________________________
ICLatexTabular get_tabEvTrig(){

  ICLatexTabular tabEvTrig(9,11);
  tabEvTrig.setTabularPrecision(".2");
  
  tabEvTrig.setColumnDecorationBefore( 0,"|");
  tabEvTrig.setColumnDecorationAfter ( 0,"||");
  tabEvTrig.setColumnDecorationAfter ( 2,"||");
  tabEvTrig.setColumnDecorationAfter ( 4,"||");
  tabEvTrig.setColumnDecorationAfter ( 6,"||");
  tabEvTrig.setColumnDecorationAfter ( 8,"||");
  tabEvTrig.setColumnDecorationAfter (10,"|");
  
  tabEvTrig.setRowDecorationBefore(0,"\\hline");
  tabEvTrig.setRowDecorationBefore(1,"\\hline");
  tabEvTrig.setRowDecorationBefore(2,"\\hline \\hline");
  tabEvTrig.setRowDecorationAfter (8,"\\hline");
  
  tabEvTrig.setCellContent(1, 0,"Sample");
  tabEvTrig.setCellContent(0, 1, "80to120"); tabEvTrig.setCellContent(1, 1,"Inc");
  tabEvTrig.setCellContent(0, 2, "80to120"); tabEvTrig.setCellContent(1, 2,"VBF");
  tabEvTrig.setCellContent(0, 3,"120to170"); tabEvTrig.setCellContent(1, 3,"Inc");
  tabEvTrig.setCellContent(0, 4,"120to170"); tabEvTrig.setCellContent(1, 4,"VBF");
  tabEvTrig.setCellContent(0, 5,"170to300"); tabEvTrig.setCellContent(1, 5,"Inc");
  tabEvTrig.setCellContent(0, 6,"170to300"); tabEvTrig.setCellContent(1, 6,"VBF");
  tabEvTrig.setCellContent(0, 7,"300to470"); tabEvTrig.setCellContent(1, 7,"Inc");
  tabEvTrig.setCellContent(0, 8,"300to470"); tabEvTrig.setCellContent(1, 8,"VBF");
  tabEvTrig.setCellContent(0, 9,"470to600"); tabEvTrig.setCellContent(1, 9,"Inc");
  tabEvTrig.setCellContent(0,10,"470to600"); tabEvTrig.setCellContent(1,10,"VBF");
 
  return tabEvTrig;
}
  
//_____________________________________________________
ICLatexTabular get_tabEvWeighted(){
  
  ICLatexTabular tabEvWeighted(9,11);
  tabEvWeighted.setTabularPrecision(".2");
  
  tabEvWeighted.setColumnDecorationBefore( 0,"|");
  tabEvWeighted.setColumnDecorationAfter ( 0,"||");
  tabEvWeighted.setColumnDecorationAfter ( 2,"||");
  tabEvWeighted.setColumnDecorationAfter ( 4,"||");
  tabEvWeighted.setColumnDecorationAfter ( 6,"||");
  tabEvWeighted.setColumnDecorationAfter ( 8,"||");
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
  
  return tabEvWeighted;
}
  
//_____________________________________________________
ICLatexTabular get_tabEvTotalWeighted(){
  
  ICLatexTabular tabEvTotalWeighted(8,3);
  tabEvTotalWeighted.setTabularPrecision(".2");
  
  tabEvTotalWeighted.setColumnDecorationBefore( 0,"|");
  tabEvTotalWeighted.setColumnDecorationAfter ( 0,"||");
  tabEvTotalWeighted.setColumnDecorationAfter ( 2,"|");
  
  tabEvTotalWeighted.setRowDecorationBefore(0,"\\hline");
  tabEvTotalWeighted.setRowDecorationBefore(1,"\\hline \\hline");
  tabEvTotalWeighted.setRowDecorationAfter (7,"\\hline");
  
  tabEvTotalWeighted.setCellContent(0, 0,"Sample");
  tabEvTotalWeighted.setCellContent(0, 1,"Inc");
  tabEvTotalWeighted.setCellContent(0, 2,"VBF");
  
  return tabEvTotalWeighted;
}

//_____________________________________________________
ICLatexTabular get_tabEvAllTrig(){
  
  ICLatexTabular tabEvAllTrig(8,13);
  tabEvAllTrig.setTabularPrecision(".2");
  
  tabEvAllTrig.setTabularColumnDecoration("|");
  tabEvAllTrig.setColumnDecorationAfter(0,"||");
  
  tabEvAllTrig.setRowDecorationBefore(0,"\\hline");
  tabEvAllTrig.setRowDecorationBefore(1,"\\hline \\hline");
  tabEvAllTrig.setRowDecorationAfter (7,"\\hline");
  
  tabEvAllTrig.setCellContent(0, 0,    "Sample");
  tabEvAllTrig.setCellContent(0, 1,    "30to50");
  tabEvAllTrig.setCellContent(0, 2,    "50to80");  
  tabEvAllTrig.setCellContent(0, 3,   "80to120");
  tabEvAllTrig.setCellContent(0, 4,"  120to170");
  tabEvAllTrig.setCellContent(0, 5,"  170to300");
  tabEvAllTrig.setCellContent(0, 6,"  300to470");
  tabEvAllTrig.setCellContent(0, 7,"  470to600"); 
  tabEvAllTrig.setCellContent(0, 8,"  600to800"); 
  tabEvAllTrig.setCellContent(0, 9," 800to1000"); 
  tabEvAllTrig.setCellContent(0,10,"1000to1400");
  tabEvAllTrig.setCellContent(0,11,"1400to1800");
  tabEvAllTrig.setCellContent(0,12,      "1800");
  
  return tabEvAllTrig;
  
}

//_____________________________________________________
ICLatexTabular get_tabEvAllTotalWeighted(){
  
  ICLatexTabular tabEvTotalWeighted(8,3);
  tabEvTotalWeighted.setTabularPrecision(".2");
  
  tabEvTotalWeighted.setColumnDecorationBefore( 0,"|");
  tabEvTotalWeighted.setColumnDecorationAfter ( 0,"||");
  tabEvTotalWeighted.setColumnDecorationAfter ( 2,"|");
  
  tabEvTotalWeighted.setRowDecorationBefore(0,"\\hline");
  tabEvTotalWeighted.setRowDecorationBefore(1,"\\hline \\hline");
  tabEvTotalWeighted.setRowDecorationAfter (7,"\\hline");
  
  tabEvTotalWeighted.setCellContent(0, 0,"Sample");
  tabEvTotalWeighted.setCellContent(0, 1,"Inc");
  
  return tabEvTotalWeighted;
}