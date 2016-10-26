/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "mooSynth.h"
#include "voices.h"
#include "../JuceLibraryCode/JuceHeader.h"


extern "C" {
#include "soundpipe.h"
}

//==============================================================================
/**
*/
class MoobotAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    MoobotAudioProcessor();
    ~MoobotAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet) override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    void setReverbDecay(float decay);
    
    float noteOnVel;
    MooVoice *voice[MOO_MAXVOICES];

private:
    //==============================================================================
    
    Synthesiser synth;
    float* audioBuffer[2]; // multichannel audio buffer used both for input and output
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MoobotAudioProcessor)
    MapUI synthControl;
    sp_data *sp;
    sp_revsc *reverb;
    
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
