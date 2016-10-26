import("stdfaust.lib");
import("filter.lib");


freq=nentry("freq",24,0,127,0.01) :si.smoo;
vel=nentry("vel",0.5,0,1,0.01) :si.smoo;
gain = hslider("gain",1,0,1,0.01) :si.smoo;


vib=nentry("vib",0.5,0,10,0.01) :si.smoo;

posSlider = hslider("formant",1,0,1,.01) : si.smoo;

//sinMod = osc(0.5 + 5 * gain) * 0.1 * gain; // for vibrato

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

f1_freq_u = 350;
f1_bw_u = 10;
f1_amp_u = 1;

f2_freq_u = 600;
f2_bw_u = 8;
f2_amp_u = 0.6;

f3_freq_u = 600;
f3_bw_u = 3;
f3_amp_u = 0.7;

speed = hslider("wowspeed", 0.09, 0.05, 1.0, 0.001):si.smoo;

tgate = ba.countup(20000, 1 - gate) != 0 : en.smoothEnvelope(speed);

pos = posSlider * tgate;


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

freq2=(ba.midikey2hz(freq + 0.5 * sinMod * gain));
envAmp = hslider("envAmp", .1, .001, 1, 0.001) : si.smoo;
env = en.smoothEnvelope(envAmp, gate);
//saw = gate:en.adsr(0.3,0.1,0.2,0.4,gate)*(os.saw2(freq2): bpfChain*vel);
//saw = os.saw2(ba.midikey2hz(freq)) * vel : fi.lowpass(2, 900) * env;
cutoff = hslider("cutoff", 1000, 10, 10000, 1) : si.smoo;
//saw = os.saw2(ba.midikey2hz(freq)) * vel : fi.lowpass(2, cutoff) * env;
voice = os.pulsetrain(ba.midikey2hz(freq)+sinMod,0.1) * vel : bpfChain * env;


synth=voice,env;
//synth = _ + saw, _ + saw;
process=hgroup("main", synth);


