import("stdfaust.lib");

freq=nentry("freq",24,0,127,0.01) :si.smoo;
//process = os.oscsin(freq);
process=hgroup("main",os.saw2(ba.midikey2hz(freq))<:_,_);


