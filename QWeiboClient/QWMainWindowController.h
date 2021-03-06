//
//  QWMainWindow.h
//  QWeiboClient
//
//  Created by  on 11-9-1.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "QWVerifyWindowController.h"
#import <QWeiboSDK/QWeiboAsyncApi.h>
#import <QWeiboSDK/QWMessage.h>
#import "QWViewImageWindowController.h"
#import <Growl/Growl.h>

typedef enum {
    QWShowTabTimeline = 1,
    QWShowTabMethions,
    QWShowTabMessages,
    QWShowTabFavorites,
    QWShowTabPeople,
    QWShowTabSearch
} QWShowTab;

@interface QWMainWindowController : NSWindowController<GrowlApplicationBridgeDelegate, NSWindowDelegate>
{
    NSMutableDictionary *allControllers;
    NSViewController *currentViewController;
    QWShowTab selectedTab;
    QWeiboAsyncApi *api;
}

@property (assign) NSViewController* currentViewController;
@property (assign) IBOutlet NSTextField *statusLabel;
@property (assign) IBOutlet NSButton *headButton;
@property (assign) IBOutlet NSImageView *timelineBadge;
@property (assign) IBOutlet NSImageView *mentionsBadge;
@property (assign) IBOutlet NSImageView *messagesBadge;
@property (assign) TweetType selectedTweetType;
@property (assign) IBOutlet NSMatrix *matrix;
@property (readonly, retain) QWViewImageWindowController *viewImageController;

- (IBAction)switchButtonClicked:(id)sender;
- (void)toggleTab:(QWShowTab)tab withInfo:(NSDictionary *)info refresh:(BOOL)refresh;
- (IBAction)publishMessage:(id)sender;
- (IBAction)logout:(id)sender;
- (void)retweetMessage:(QWMessage *)message;
- (IBAction)headButtonClicked:(id)sender;

@end
