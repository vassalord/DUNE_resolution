!/bin/sh
 rm -rf ./data
 mkdir data
 cd ./data

source /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh
setup garsoft v02_18_00 -q e20:prof


for p in 0.2 0.25 0.3 0.4 0.5 0.6 0.7; do
mkdir $p
cd $p

# customize our job configuration.  set the input text file

cat > onetg.fcl <<EOF
#include "prodtext.fcl"
physics.producers.generator.InputFileName: "proton.txt"

EOF

# turn on trajectory saving in the anatree

cat > tmpana.fcl <<EOF
#include "anajob.fcl"
physics.analyzers.anatree.WriteMCPTrajectory: true
physics.analyzers.anatree.WriteMCPTrajMomenta: true
physics.analyzers.anatree.WriteHits: true
physics.analyzers.anatree.WriteTrackTrajectories: true

EOF


e=`echo "sqrt(${p}^2 + 3.72^2)" | bc`
for ((i = 1; i<=100; i++))
do

x=$(shuf -i 0-250 -n1)
y=$(shuf -i 0-300 -n1)
z=$(shuf -i 1300-1600 -n1)


cat >> proton.txt <<EOF 
1 1
1 1000020040 0 0 0 0 0. 0. ${p} ${e} 3.72 ${x}.0 -${y}.0 ${z}.0 0.0

EOF
done
art -n 100 -c onetg.fcl -o tgen.root
art -c readoutsimjob.fcl -o treadoutsim.root tgen.root
art -c recojob.fcl -o trec.root treadoutsim.root
art -c tmpana.fcl trec.root

root -b anatree.root <<EOF
TCanvas *mycanvas = new TCanvas("c1","c1",800,800);
gDirectory->cd("anatree");
GArAnaTree->Draw("HitX");
mycanvas->Print("hitx.png");
.q
EOF

root -b anatree.root <<EOF
TCanvas *mycanvas = new TCanvas("c1","c1",800,800);
gDirectory->cd("anatree");
GArAnaTree->Draw("HitY");
mycanvas->Print("hity.png");
.q
EOF

root -b anatree.root <<EOF
TCanvas *mycanvas = new TCanvas("c1","c1",800,800);
gDirectory->cd("anatree");
GArAnaTree->Draw("HitZ");
mycanvas->Print("hitz.png");
.q
EOF

root -b anatree.root <<EOF
TCanvas *mycanvas = new TCanvas("c1","c1",800,800);
gDirectory->cd("anatree");
GArAnaTree->Draw("HitSig");
mycanvas->Print("hitsig.png");
.q
EOF

root -b anatree.root <<EOF
TCanvas *mycanvas = new TCanvas("c1","c1",800,800);
gDirectory->cd("anatree");
GArAnaTree->Draw("HitRMS");
mycanvas->Print("hitrsm.png");
.q
EOF

root -b anatree.root <<EOF
TCanvas *mycanvas = new TCanvas("c1","c1",800,800);
gDirectory->cd("anatree");
GArAnaTree->Draw("HitChan");
mycanvas->Print("hitchan.png");
.q
EOF


root -b anatree.root <<EOF
TCanvas *mycanvas = new TCanvas("c1","c1",800,800);
gDirectory->cd("anatree");
GArAnaTree->Draw("TrajMCPPZ");
mycanvas->Print("tmp.png");
.q
EOF

root -b anatree.root <<EOF
TCanvas *mycanvas = new TCanvas("c1","c1",800,800);
gDirectory->cd("anatree");
GArAnaTree->Draw("TPCClusterMCindex");
mycanvas->Print("cindex.png");
.q
EOF

root -b anatree.root <<EOF
TCanvas *mycanvas = new TCanvas("c1","c1",800,800);
gDirectory->cd("anatree");
GArAnaTree->Draw("TPCClusterX");
mycanvas->Print("clusterx.png");
.q
EOF

root -b anatree.root <<EOF
TCanvas *mycanvas = new TCanvas("c1","c1",800,800);
gDirectory->cd("anatree");
GArAnaTree->Draw("TPCClusterY");
mycanvas->Print("clustery.png");
.q
EOF

root -b anatree.root <<EOF
TCanvas *mycanvas = new TCanvas("c1","c1",800,800);
gDirectory->cd("anatree");
GArAnaTree->Draw("TPCClusterZ");
mycanvas->Print("clusterz.png");
.q
EOF


mv hitx.png HitX_${p}.png

mv hity.png HitY_${p}.png

mv hitz.png HitZ_${p}.png

mv hitsig.png HitSig_${p}.png

mv hitrsm.png HitRSM_${p}.png

mv hitchan.png HitChan_${p}.png




mv tmp.png mcppz_${p}.png

mv cindex.png TPCClusterMCindex_${p}.png

mv clusterx.png TPCClusterX_${p}.png

mv clustery.png TPCClusterY_${p}.png

mv clusterz.png TPCClusterZ_${p}.png


cd ../
done
