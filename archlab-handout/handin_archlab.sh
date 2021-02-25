#!/bin/bash
set -e

echo "What is your BYU NetID?"
read netid
echo "Hello, $netid!"

if [ -d handin ]; then
  rm -r handin
fi

echo "Start packing ..."
mkdir handin

mkdir handin/parta
cp sim/misc/sum.ys handin/parta/${netid}-sum.ys
cp sim/misc/rsum.ys handin/parta/${netid}-rsum.ys
cp sim/misc/copy.ys handin/parta/${netid}-copy.ys

mkdir handin/partb
cp sim/seq/seq-full.hcl handin/partb/${netid}-seq-full.hcl

mkdir handin/partc
cp sim/pipe/ncopy.ys handin/partc/${netid}-ncopy.ys
cp sim/pipe/pipe-full.hcl handin/partc/${netid}-pipe-full.hcl
tar -cvf ${netid}-handin.tar handin

rm -r handin
echo "Done."
