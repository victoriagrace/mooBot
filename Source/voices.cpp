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
    synthControl.setParamValue("/main/vel", .5);
    
    
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

    compute(numSamples, NULL, audioBuffer);
}



