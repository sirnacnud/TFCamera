//
//  TFCameraViewController.h
//  camera
//
//  Created by Tarik Fayad on 4/2/16.
//  Copyright © 2016 Tarik Fayad. All rights reserved.
//

#import <UIKit/UIKit.h>
/*!
 Call the following to init the Camera VC for display
 
 TFCameraViewController *cameraVC = [TFCameraViewController withDefaultInterface];
 */


@class TFCameraViewController;
@protocol TFCameraViewControllerDelegate <NSObject>
/*!
 Camera notifies the delegate that a photo was taken and sends the photo;
 */
- (void)cameraDidTakePhoto:(UIImage *)photo;

/*!
 Camera notifies the delegate that a video was taken and send the video;
 */
- (void)cameraDidTakeVideo:(NSURL *)videoURL;

@end

@interface TFCameraViewController : UIViewController

@property (nonatomic, weak) id<TFCameraViewControllerDelegate> delegate;

@property (nonatomic) BOOL enableDoubleTapSwitch; //Default is YES
@property (nonatomic) BOOL enableSelfieFlash; //Default is YES
@property (nonatomic) BOOL enableShutterAnimation; //Default is YES

@property (nonatomic) CGFloat maxVideoLength; //Default is 16 seconds
@property (nonatomic) CGFloat shutterAnimationSpeed; //Default is .15 seconds

@property (strong, nonatomic) UIColor *appColor; //Default is white

/*!
 Use these methods to swap the button images after instantiaiton of the ViewController
 */

- (void) changeFlashOnImage: (UIImage *) flashOnImage;
- (void) changeFlashOffImage: (UIImage *) flashOffImage;
- (void) changeSwapCameraImage: (UIImage *) swapCameraImage;


/*!
 This is the default instantion method. Incudes regular and selfie flash, video recording, camera swapping, tap to focus, and doubletap to switch cameras.
 
 This is now deprecated, use [TFCameraViewController withDefaultInterface].
 */
- (instancetype) initWithInterface __attribute__((deprecated("Replaced by +withDefaultInterface")));

/*!
 This is the default instantion method. Incudes regular and selfie flash, video recording, camera swapping, tap to focus, and doubletap to switch cameras.
 */
+ (instancetype) withDefaultInterface;

/*!
 Use these methods to register or remove the camera view controller for a color change notificaiton (all the button colors will change on the camera screen when this notification fires).
 */
- (void) registerCameraForColorChangeNotification: (NSString *) notificationString;
- (void) removeColorChangeNotificationFromCamera;

@end
