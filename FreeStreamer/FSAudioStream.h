/*
 * This file is part of the FreeStreamer project,
 * (C)Copyright 2011 Matias Muhonen <mmu@iki.fi>
 * See the file ''LICENSE'' for using the code.
 */

#import <Foundation/Foundation.h>

extern NSString* const FSAudioStreamStateChangeNotification;
extern NSString* const FSAudioStreamNotificationKey_State;

extern NSString* const FSAudioStreamErrorNotification;
extern NSString* const FSAudioStreamNotificationKey_Error;

extern NSString* const FSAudioStreamMetaDataNotification;
extern NSString* const FSAudioStreamNotificationKey_MetaData;

typedef enum {
    kFsAudioStreamRetrievingURL,
    kFsAudioStreamStopped,
    kFsAudioStreamBuffering,
    kFsAudioStreamPlaying,
    kFsAudioStreamFailed
} FSAudioStreamState;

typedef enum {
    kFsAudioStreamErrorOpen = 1,
    kFsAudioStreamErrorStreamParse = 2,
    kFsAudioStreamErrorNetwork = 3
} FSAudioStreamError;

@class FSAudioStreamPrivate;

typedef struct {
    unsigned minute;
    unsigned second;
} FSPlaybackTime;

@interface FSAudioStream : NSObject {
    FSAudioStreamPrivate *_private;
}

- (void)play;
- (void)playFromURL:(NSURL*)url;
- (void)stop;
- (void)pause;

@property (nonatomic,assign) NSURL *url;
@property (nonatomic,readonly) FSPlaybackTime currentTimePlayed;

@end
