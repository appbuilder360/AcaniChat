// Old
#import <AudioToolbox/AudioToolbox.h>
#import "XMPPRoom.h"
#import "XMPPRoomMessageCoreDataStorageObject.h"

#import "RoomOccupantsViewController.h"

@class Message;

@interface ChatViewController : UIViewController <NSFetchedResultsControllerDelegate,
UITableViewDelegate, UITableViewDataSource, UITextViewDelegate, UIActionSheetDelegate,XMPPRoomDelegate, WEPopoverControllerDelegate, UIPopoverControllerDelegate> {

    WEPopoverController * iPhonePopover;
    UIPopoverController * iPadPopover;
    UIBarButtonItem * occupantsButton;
}

@property(nonatomic,strong) WEPopoverController * iPhonePopover;
@property(nonatomic,strong) UIPopoverController * iPadPopover;

@property(nonatomic,strong) UIBarButtonItem * occupantsButton;

@property (nonatomic, assign) SystemSoundID receiveMessageSound;

@property (nonatomic, retain) UITableView *chatContent;

@property (nonatomic, retain) UIImageView *chatBar;
@property (nonatomic, retain) UITextView *chatInput;
@property (nonatomic, assign) CGFloat previousContentHeight;
@property (nonatomic, retain) UIButton *sendButton;

@property (nonatomic, copy) NSMutableArray *cellMap;

@property (nonatomic, retain) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, retain) NSFetchedResultsController *fetchedResultsController;
@property(nonatomic, strong)XMPPRoom * room;

- (void)enableSendButton;
- (void)disableSendButton;
- (void)resetSendButton;

- (void)keyboardWillShow:(NSNotification *)notification;
- (void)keyboardWillHide:(NSNotification *)notification;
- (void)resizeViewWithOptions:(NSDictionary *)options;
- (void)scrollToBottomAnimated:(BOOL)animated;

- (void)sendMessage;
- (void)clearChatInput;
- (NSUInteger)addMessage:(XMPPRoomMessageCoreDataStorageObject *)message;
- (NSUInteger)removeMessageAtIndex:(NSUInteger)index;
- (void)clearAll;
-(void)showRoomOccupants;
- (void)fetchResults;



@end
