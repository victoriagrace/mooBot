/*
  ==============================================================================

    voices.h
    Created: 22 Oct 2016 3:52:34pm
    Author:  Victoria Grace

  ==============================================================================
*/

#ifndef VOICES_H_INCLUDED
#define VOICES_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"
#include "mooSynth.h"

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

struct MooSound : public SynthesiserSound
{
    MooSound() {}
    
    bool appliesToNote (int /*midiNoteNumber*/) override        { return true; }
    bool appliesToChannel (int /*midiChannel*/) override        { return true; }
};


struct MooVoice : public SynthesiserVoice
{
    bool canPlaySound(SynthesiserSound* sound) override
    {
        return dynamic_cast<MooSound*> (sound) != nullptr;
    }
    
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound*, int /* pitchwheel */) override
    {
        synthControl.setParamValue("/main/freq",midiNoteNumber);
        synthControl.setParamValue("/main/vel",velocity);
    }
    void stopNote (float/*velocity*/, bool allowTailOff) override
    {
        synthControl.setParamValue("/main/vel",0.f);

    }
    void pitchWheelMoved (int /*newValues*/) override
    {
    }
    
    void controllerMoved (int /*controllerNumber*/, int /*newValue*/) override
    {
    }
    
    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;
    
    void init(double samplingRate);
    void compute(int count, FAUSTFLOAT **in, FAUSTFLOAT **out);
    void setCurrentPlaybackSampleRate(double newRate) override;

    
    
private:
    mooSynth faustSynth;
    MapUI synthControl;
    float *audioBuffer[2];
};


#endif  // VOICES_H_INCLUDED
