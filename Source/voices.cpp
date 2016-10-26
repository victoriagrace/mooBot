/*
  ==============================================================================

    voices.cpp
    Created: 22 Oct 2016 3:52:34pm
    Author:  Victoria Grace

  ==============================================================================
*/

#include "voices.h"

void MooVoice::init(double samplingRate)
{
    faustSynth.init(samplingRate);
    faustSynth.buildUserInterface(&synthControl);
    
    synthControl.setParamValue("/main/freq",32);
    synthControl.setParamValue("/main/vel", 0);
    
    
}

void MooVoice::compute(int count, FAUSTFLOAT **in, FAUSTFLOAT **out)
{
    faustSynth.compute(count, in, out);
}

void MooVoice::setCurrentPlaybackSampleRate(double newRate)
{
    init(newRate);
}

void MooVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    /* we want this to work */
    audioBuffer[0] = outputBuffer.getWritePointer(0);
    audioBuffer[1] = outputBuffer.getWritePointer(1);
    float *tmp[] = { &synth, &env };
    //compute(numSamples, audioBuffer, audioBuffer);
    int s;
    int nsmp = numSamples;
    if(mode > 0) {
    
//        for(s = startSample; s < numSamples; s++) {
//            compute(1, NULL, tmp);
//            audioBuffer[0][s] += tmpL;
//            audioBuffer[1][s] += tmpR;
//        }
        
        while(--numSamples >= 0) {
            compute(1, NULL, tmp);
            for(int i = outputBuffer.getNumChannels(); --i >= 0;) {
                outputBuffer.addSample(i, startSample, synth);
            }
            ++startSample;

            if(mode == 2) {
                if(env < 0.001 ) {
                    mode = 0;
                    clearCurrentNote();
                }
            }
        }

        
    }
    
//
//    
//    if(isOn == false && pleaseTurnOff == false && isStarted == true) {
//        timer -= numSamples;
//        if(timer <= 0) {
//            isStarted = false;
//            clearCurrentNote();
//            std::cout << "Turning off note.\n";
//        }
//    }
//    
//    if(pleaseTurnOff == true) {
//        std::cout << "Triggered for release!\n";
//        isOn = false;
//        pleaseTurnOff = false;
//        timer = 44100;
//    }
    

}

void MooVoice::setCutoff(float cutoff)
{
    synthControl.setParamValue("/main/cutoff",cutoff);
}



