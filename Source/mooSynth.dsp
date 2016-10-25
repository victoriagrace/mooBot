import("stdfaust.lib");
import("filter.lib");


freq=nentry("freq",24,0,127,0.01) :si.smoo;
vel=nentry("vel",0.5,0,1,0.01) :si.smoo;

vib=nentry("vib",0.5,0,6,0.01) :si.smoo;
pos= hslider("formant",0,0,1,.01) : si.smoo;

sinMod=os.osc(vib);
gate= checkbox("gate");

f1_freq_oo = 400;
f1_bw_oo = 10;
f1_amp_oo = 1;

f2_freq_oo = 750;
f2_bw_oo = 10;
f2_amp_oo = 0.7;

f3_freq_oo = 2400;
f3_bw_oo = 5;
f3_amp_oo = 0.5;

f1_freq_u = 250;
f1_bw_u = 10;
f1_amp_u = 1;

f2_freq_u = 595;
f2_bw_u = 10;
f2_amp_u = 0.65;

f3_freq_u = 345;
f3_bw_u = 5;
f3_amp_u = 0.9;

f1_freq = pos * f1_freq_oo + (1 - pos) * f1_freq_u;
f1_bw = pos * f1_bw_oo + (1 - pos) * f1_bw_u;
f1_amp = pos * f1_amp_oo + (1 - pos) * f1_amp_u;

f2_freq = pos * f2_freq_oo + (1 - pos) * f2_freq_u;
f2_bw = pos * f2_bw_oo + (1 - pos) * f2_bw_u;
f2_amp = pos * f2_amp_oo + (1 - pos) * f2_amp_u;

f3_freq = pos * f3_freq_oo + (1 - pos) * f3_freq_u;
f3_bw = pos * f3_bw_oo + (1 - pos) * f3_bw_u;
f3_amp = pos * f3_amp_oo + (1 - pos) * f3_amp_u;


bpfChain=resonbp(f1_freq,f1_bw,f1_amp):
resonbp(f2_freq,f2_bw,f2_amp):
resonbp(f3_freq,f3_bw,f3_amp);

freq2=(ba.midikey2hz(freq))+sinMod;

saw = gate:en.adsr(0.3,0.1,0.2,0.4)*(os.saw2(freq2): bpfChain*vel);
//synth=saw,saw;
synth = _ + 0.25*saw, _ + 0.25*saw;
process=hgroup("main", synth);


