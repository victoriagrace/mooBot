/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "mooSynth.h"

//==============================================================================
/**
*/
class MoobotAudioProcessorEditor  : public AudioProcessorEditor,public SliderListener
{
public:
    MoobotAudioProcessorEditor (MoobotAudioProcessor&);
    ~MoobotAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    
    // Binary resources:
    static const char* noseEdit_paint;
    static const int noseEdit_paintSize;
    static const char* cowNose_paint;
    static const int cowNose_paintSize;
    static const char* cowNose_jpg;
    static const int cowNose_jpgSize;


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MoobotAudioProcessor& processor;
    ScopedPointer<Slider> slider4;
    ScopedPointer<Slider> slider1;
    ScopedPointer<Slider> slider5;
    ScopedPointer<Slider> slider2;
    ScopedPointer<Slider> slider3;
    Path internalPath1;
    Path internalPath2;
    Path internalPath3;
    Path internalPath4;
    Path internalPath5;
    Path internalPath6;
    Path internalPath7;
    Path internalPath8;
    Path internalPath9;
    Path internalPath10;
    Path internalPath11;
    Path internalPath12;
    Path internalPath13;
    Path internalPath14;
    
    MapUI synthControl;

    mooSynth fSynth;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MoobotAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
