/*
 *  Copyright (C) 2005-2020 Team Kodi
 *  https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSE.md for more information.
 */

#pragma once

#include "../Channels.h"
#include "BaseEntry.h"
#include "Channel.h"
#include "Tags.h"

#include <string>

#include <kodi/libXBMC_pvr.h>
#include <tinyxml.h>

namespace enigma2
{
  namespace data
  {
    static const std::string TAG_FOR_PLAY_COUNT = "PlayCount";
    static const std::string TAG_FOR_LAST_PLAYED = "LastPlayed";
    static const std::string TAG_FOR_NEXT_SYNC_TIME = "NextSyncTime";

    class RecordingEntry : public BaseEntry, public Tags
    {
    public:
      const std::string& GetRecordingId() const { return m_recordingId; }
      void SetRecordingId(const std::string& value) { m_recordingId = value; }

      time_t GetStartTime() const { return m_startTime; }
      void SetStartTime(time_t value) { m_startTime = value; }

      int GetDuration() const { return m_duration; }
      void SetDuration(int value) { m_duration = value; }

      int GetPlayCount() const { return m_playCount; }
      void SetPlayCount(int value) { m_playCount = value; }

      int GetLastPlayedPosition() const { return m_lastPlayedPosition; }
      void SetLastPlayedPosition(int value) { m_lastPlayedPosition = value; }

      time_t GetNextSyncTime() const { return m_nextSyncTime; }
      void SetNextSyncTime(time_t value) { m_nextSyncTime = value; }

      const std::string& GetStreamURL() const { return m_streamURL; }
      void SetStreamURL(const std::string& value) { m_streamURL = value; }

      const std::string& GetEdlURL() const { return m_edlURL; }
      void SetEdlURL(const std::string& value) { m_edlURL = value; }

      const std::string& GetChannelName() const { return m_channelName; }
      void SetChannelName(const std::string& value) { m_channelName = value; }

      int GetChannelUniqueId() const { return m_channelUniqueId; }
      void SetChannelUniqueId(int value) { m_channelUniqueId = value; }

      const std::string& GetDirectory() const { return m_directory; }
      void SetDirectory(const std::string& value) { m_directory = value; }

      const std::string& GetIconPath() const { return m_iconPath; }
      void SetIconPath(const std::string& value) { m_iconPath = value; }

      int GetStreamProgramNumber() const { return m_streamProgramNumber; }
      void SetStreamProgramNumber(int value) { m_streamProgramNumber = value; }

      bool HasStreamProgramNumber() const { return m_hasStreamProgramNumber; }

      bool IsRadio() const { return m_radio; }
      void SetRadio(bool value) { m_radio = value; }

      bool IsDeleted() const { return m_deleted; }
      void SetDeleted(bool value) { m_deleted = value; }

      const std::string& GetStartTimeW3CDate() const { return m_startTimeW3CDateString; }
      void SetStartTimeW3CDate(const std::string& value) { m_startTimeW3CDateString = value; }      

      int GetSizeInBytes() const { return m_sizeInBytes; }
      void SetSizeInBytes(int value) { m_sizeInBytes = value; }

      bool UpdateFrom(TiXmlElement* recordingNode, const std::string& directory, bool deleted, enigma2::Channels& channels);
      void UpdateTo(PVR_RECORDING& left, Channels& channels, bool isInRecordingFolder);

    private:
      long TimeStringToSeconds(const std::string& timeString);

      std::shared_ptr<Channel> FindChannel(enigma2::Channels& channels) const;
      std::shared_ptr<Channel> GetChannelFromChannelReferenceTag(enigma2::Channels& channels) const;
      std::shared_ptr<Channel> GetChannelFromChannelNameSearch(enigma2::Channels& channels) const;
      std::shared_ptr<Channel> GetChannelFromChannelNameFuzzySearch(enigma2::Channels& channels) const;

      std::string m_recordingId;
      time_t m_startTime;
      int m_duration;
      int m_playCount = 0;
      int m_lastPlayedPosition = 0;
      time_t m_nextSyncTime = 0;
      std::string m_streamURL;
      std::string m_edlURL;
      std::string m_channelName;
      int m_channelUniqueId = PVR_CHANNEL_INVALID_UID;
      std::string m_directory;
      std::string m_iconPath;
      mutable bool m_radio = false;
      mutable bool m_haveChannelType = false;
      mutable bool m_anyChannelTimerSource = false;
      bool m_deleted = false;
      mutable int m_streamProgramNumber;
      mutable bool m_hasStreamProgramNumber = false;
      std::string m_startTimeW3CDateString;
      int64_t m_sizeInBytes = 0;
    };
  } //namespace data
} //namespace enigma2