void EffMapDplusTask(){
 //------------Root Style----------------------------------------
        gROOT->ForceStyle(); 
        gStyle->SetStatW(0.20);
        gStyle->SetStatH(0.17);
       // gStyle->SetStatFontSize(1.0);
        gStyle->SetOptTitle(1);
        gStyle->SetFuncWidth(3.0);
        gStyle->SetTitleOffset(1.5,"XY");
        gStyle->SetTitleOffset(1.0,"Z");
        gStyle->SetTitleSize(0.07,"A");
       // gStyle->SetTitleFont(62,"A");
	gStyle->SetTitleSize(.05,"X");gStyle->SetTitleSize(.05,"YZ");
	gStyle->SetLabelSize(.04,"X");gStyle->SetLabelSize(.04,"Y");
	gStyle->SetLabelSize(.04,"Z");
	gStyle->SetHistLineWidth(2);
	gStyle->SetOptFit(1);
        //gStyle->SetOptFit(0111);
        gStyle->SetOptStat(1);
 
 TFile* Limacc2d = TFile::Open("EfficiencyMap_2D_Dplus5TeV_c_wLimAcc.root");
 TCanvas *c1 = new TCanvas("c1","Efficiency",2000,1200);
 TH2D *h2dLimAcc = (TH2D*)Limacc2d->Get("h_Eff")->Clone("heff2D_rebin");
 h2dLimAcc->GetZaxis()->SetTitle("Acceptance #times Efficiency");
 h2dLimAcc->GetXaxis()->SetTitle("Pt [Gev/c]");
 h2dLimAcc->GetYaxis()->SetTitle("Multiplicity");
 h2dLimAcc->GetXaxis()->CenterTitle();
 h2dLimAcc->GetYaxis()->CenterTitle();
 h2dLimAcc->GetZaxis()->CenterTitle();
 h2dLimAcc->GetXaxis()->SetRangeUser(0.0,24.0);
 h2dLimAcc->SetTitle("RecoPID/LimAcc");
 c1->cd();
 h2dLimAcc->Draw("lego2Z");
 c1->SaveAs("EffMap_2D_c_wLimAcc_ForDplusTask.root");

}
