void numTcross(){
ifstream cin("limit.txt");





TPaveText *tpav_txt00 = new TPaveText(0.190,1.0230025,0.097052174,0.8010471,"brNDC");
tpav_txt00->SetBorderSize(0);
tpav_txt00->SetFillStyle(0);
tpav_txt00->SetTextAlign(10);
tpav_txt00->SetTextFont(42);
tpav_txt00->SetTextSize(0.045);
tpav_txt00->SetTextColor(kBlack);
tpav_txt00->AddText("#font[22]{CMS}");
TPaveText *tpav_txt010 = new TPaveText(0.375,1.0025,0.165052174,0.8010471,"brNDC");
tpav_txt010->SetBorderSize(0);
tpav_txt010->SetFillStyle(0);
tpav_txt010->SetTextAlign(10);
tpav_txt010->SetTextFont(42);
tpav_txt010->SetTextSize(0.045);
tpav_txt010->SetTextColor(kBlack);
tpav_txt010->AddText("#font[52]{Preliminary}");
TPaveText *tpav_txtt = new TPaveText(0.73043478,0.9148342,0.6652174,0.89010471,"brNDC");

tpav_txtt->SetBorderSize(0);
tpav_txtt->SetFillStyle(0);
tpav_txtt->SetTextAlign(11);
tpav_txtt->SetTextFont(42);
tpav_txtt->SetTextSize(0.04);
tpav_txtt->SetTextColor(kBlack);
//tpav_txt->AddText("#gamma+ Jets");
tpav_txtt->AddText("2.6fb^{-1},  #sqrt{s}=13 TeV");








 TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);

   c1->SetGrid();
   c1->DrawFrame(200,200,1400,12);
   c1->SetLogy();

double a,b,c,d,e,f,sf;
double x[27],y[27],z[27],eyl[27],eyh[27],ey2l[27],ey2h[27];
int n=27;
double obs[27]={ 27771.6671876,  12119.8163867,  5689.65773549,  2776.45839259, 1480.74905979,  800.309546726,  461.64716787,  268.713684687, 166.511121257,  107.7246132,  69.5398773928,  45.0741516048,  30.6887098172,  20.6858460637,  14.3967978196,  10.1038249577,  7.05775520052,  5.0881340685,  3.62423444975,  2.65594105508,  1.90564826907,  1.37413274321,  1.0445383996,  0.776398818217,  0.568763087586,  0.430481083997, 0.323880196726};
double cxn[27] = {60.6,20.3,8.04,3.59,1.74,0.906,0.496,0.284,0.169,0.103,0.0648,0.0416,0.0273,0.0182,0.0123,0.00845,0.00586,0.00411,0.00291,0.00208,0.00150,0.00109,0.000795,0.000585,0.000433,0.000321,0.000240};//,0.000180,0.000135,0.000102,0.0000774,0.0000588,0.0000448,0.0000343,0.0000262,0.0000201,0.0000155};



double cxnl[27]={53.2,17.8,7.05,3.14,1.52,0.791,0.434,0.248,0.147,0.090,0.0565,0.0363,0.0237,0.0158,0.0107,0.00733,0.00508,0.00356,0.00252,0.00180,0.00129,0.000939,0.000684,0.000503,0.000371,0.000275,0.000205};//,0.000154,0.000115,0.0000870,0.0000658,0.0000499,0.0000380,0.0000290,0.0000221,0.0000169,0.0000130};

double cxnu[27]={68.3,22.8,9.02,4.01,1.94,1.01,0.553,0.316,0.188,0.115,0.0721,0.0463,0.0303,0.0202,0.0137,0.00939,0.00653,0.00458,0.00325,0.00232,0.00167,0.00122,0.000889,0.000654,0.000485,0.000360,0.000270};//,0.000202,0.000152,0.000115,0.0000875,0.0000666,0.0000508,0.0000389,0.0000298,0.0000230,0.0000177};



double pdf[27]= {2.5,1.09,0.535,0.285,0.161,0.0952,0.0578,0.0369,0.0237,0.0157,0.0106,0.00727,0.00503,0.00355,0.00253,0.00183,0.00133,0.000982,0.000725,0.000541,0.000407,0.000309,0.000234,0.000179,0.000138,0.000106,0.0000824};


for(int i=1;i<28;i++){
sf=(cxn[i-1]);
cin>>a>>b>>c>>d>>e>>f;
//cout<<sf*a<<"   "<<sf*b<<"   "<<sf*c<<"   "<<sf*d<<"   "<<sf*e<<"   "<<sf*f<<"   "<<endl;
x[i-1]=200+((i-1)*50);
y[i-1]=(sf*c);
eyl[i-1]=(sf*b);
eyh[i-1]=(sf*d);
ey2l[i-1]=(sf*a);
ey2h[i-1]=(sf*e);
z[i-1]=(sf*f);
//cout<<eyl[i-1]<<"   "<<ey2l[i-1]<<endl;
}


TGraph *gr=new TGraph(n,x,y);
TGraph *gr1=new TGraph(n,x,eyl);
TGraph *gr2=new TGraph(n,x,eyh);


TGraph *gr21=new TGraph(n,x,ey2l);
TGraph *gr22=new TGraph(n,x,ey2h);
TGraph *grd=new TGraph(n,x,z);
TGraphErrors *grT=new TGraphErrors(n,x,cxn,NULL,pdf);




   TGraph *grshade = new TGraph(2*n);
   TGraph *grshade2 = new TGraph(2*n);
 for (int i=0;i<n;i++) {

      grshade->SetPoint(i,x[i],eyh[i]);
      grshade->SetPoint(n+i,x[n-i-1],eyl[n-i-1]);
   }


for (int i=0;i<n;i++) {

      grshade2->SetPoint(i,x[i],ey2h[i]);
      grshade2->SetPoint(n+i,x[n-i-1],ey2l[n-i-1]);
   }

   
 // grshade2->GetYaxis()->SetRangeUser(0.001,100);
grshade2->GetXaxis()->SetTitle("M_{LQ} (GeV) ");
grshade2->GetYaxis()->SetTitle("#sigma #times #beta^{2} (pb)");
//c1->GetYaxis()->SetTitle("Events");
grshade2->SetFillStyle(1000);
   grshade2->SetFillColor(kYellow);
   grshade2->Draw("af");
   gr21->Draw("l");
   gr22->Draw("l");

grshade->SetFillStyle(1001);
   grshade->SetFillColor(kGreen);
   grshade->Draw("f");
   gr1->Draw("l");
   gr2->Draw("l");

     gr->SetLineStyle(7);
   gr->SetLineWidth(2);
   gr->SetMarkerColor(0);
   gr->SetMarkerSize(0);
   gr->SetMarkerStyle(7);
   gr->Draw("C");



   grd->SetMarkerSize(0.8);
   grd->SetMarkerStyle(21);
   grd->SetLineWidth(2);
   grd->Draw("CP");


  
//********************************************************LEGEND

TLegend *leg=new TLegend(0.15,0.69,0.3,0.85);
      leg->SetHeader("Scalar LQ#bar{LQ} #rightarrow eejj");
      leg ->AddEntry(gr,"Expected 95% CL upper limit", "lp");
      leg ->AddEntry(grd,"Observed 95% CL upper limit", "lp");
      leg ->AddEntry(grT,"#sigma_{theory} #times #beta^{2} ","lp");
      leg->SetBorderSize(0);

//**************************************************Theory predicted


   grT->SetFillStyle(3001);
   grT->SetFillColor(kBlue);
   grT->SetLineWidth(2);
   grT->SetLineColor(kBlue);
   grT->Draw("3c");
leg->Draw();
tpav_txtt->Draw();
tpav_txt00->Draw();
tpav_txt010->Draw();
//********************************************************


}
