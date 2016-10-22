import("stdfaust.lib");

freq=nentry("freq",24,0,127,0.01) :si.smoo;
vel=nentry("vel",0.5,0,1,0.01) :si.smoo;

process=hgroup("main",os.saw2(ba.midikey2hz(freq))*vel<:_,_);


