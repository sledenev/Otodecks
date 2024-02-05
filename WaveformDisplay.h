//
// Created by Sergey Ledenev on 04/02/2024.
//

#ifndef OTODECKS_WAVEFORMDISPLAY_H
#define OTODECKS_WAVEFORMDISPLAY_H

#include <JuceHeader.h>

class WaveformDisplay    : public Component,
                           public ChangeListener
{
public:
    WaveformDisplay( AudioFormatManager & 	formatManagerToUse,
                     AudioThumbnailCache & 	cacheToUse );
    ~WaveformDisplay();

    void paint (Graphics&) override;
    void resized() override;

    void changeListenerCallback (ChangeBroadcaster *source) override;

    void loadURL(URL audioURL);

    /** set the relative position of the playhead*/
    void setPositionRelative(double pos);

private:
    AudioThumbnail audioThumb;
    bool fileLoaded;
    double position;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformDisplay)
};



#endif //OTODECKS_WAVEFORMDISPLAY_H
