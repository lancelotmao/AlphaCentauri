//
//  MRAppDelegate.h
//  MRuntime
//
//  Created by Lancelot on 4/25/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MRPush.h"

/*!
 @interface
 @discussion MRBaseAppDelegate provides basic functionality for mCloud applications. e.g.
 It will start background thread to check framework update; it provides entry point
 for notifications; It initialize localization, etc...
 Application delegate should always extend MRBaseAppDelegate
 */
@interface MRBaseAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

/*!
 @property
 @abstract
 @discussion use specific view controll's orientation if set; otherwise use app's orientation
 */
@property (nonatomic, strong) NSString *orientation;

/*!
 @property
 @abstract
 @discussion set in .pjt file. can be overidden by specific page
 */
@property (nonatomic, strong) NSString *appOrientation;

/*!
 @property
 @abstract
 @discussion connect to back-end after app started and download bundles if a new version is released
 */
@property (readwrite, nonatomic) BOOL autoUpgradeBundle;

/*!
 @property
 @abstract
 @discussion native listeners for example from security package. Note if navtive push listener consumes
 a push event, we will NOT notify script
 */
@property (readwrite, nonatomic) NSArray* pushListeners;

// if main bundle contains 'Bundles.zip' file, we will unzip it and load each framework during app launching
- (BOOL)loadBuiltInBundles;

@end
