#ifndef __GANDALF_APU_H
#define __GANDALF_APU_H

#include "bus.h"
#include "sound/frame_sequencer.h"
#include "sound/sound_channel.h"

namespace gandalf
{
    class APU : public Bus::AddressHandler
    {
    public:
        APU();
        virtual ~APU();

        void Write(word address, byte value) override;
        byte Read(word address) const override;
        std::set<word> GetAddresses() const override;

        void Tick();

        class OutputHandler
        {
        public:
            virtual ~OutputHandler() = default;

            /** Play an audio sample
             * @param left the left channel sample
             * @param right the right channel sample
             */
            virtual void Play(byte left, byte right) = 0;
        };

        void SetOutputHandler(std::shared_ptr<OutputHandler> handler);

        /** Enables / disables sound of the given channel
        * @param channel channel index (0-3)
        * @param mute whether to enable or disable sound for the given channel
        */
        void MuteChannel(int channel, bool mute);

    private:
        std::shared_ptr<OutputHandler> output_handler_;
        std::array<byte, 0x20> wave_ram_;

        FrameSequencer frame_sequencer_;
        std::array<std::unique_ptr<SoundChannel>, 4> sound_channels_;
        std::array<byte, 4> samples_;
        std::array<bool, 4> mute_channel_;

        // NR50
        bool vin_left_;
        bool vin_right_;
        byte left_volume_;
        byte right_volume_;
        // NR51
        std::array<bool, 4> channel_left_enabled_;
        std::array<bool, 4> channel_right_enabled_;
        // NR52
        bool sound_enabled_;
    };
} // namespace gandalf

#endif