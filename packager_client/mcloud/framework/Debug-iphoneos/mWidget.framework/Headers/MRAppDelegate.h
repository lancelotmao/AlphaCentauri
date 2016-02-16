//
//  MRAppDelegate.h
//  MRuntime
//
//  Created by Lancelot on 4/25/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import <MRuntime/MRuntime.h>

/*!
 @interface
 @discussion MRAppDelegate
 */
@interface MRAppDelegate : MRBaseAppDelegate

// if main bundle contains 'projectconfig.pjt' file calling this method will intepret it and start new view controller
- (void)startProject;

// same as startProject except app is in debug mode
- (void)debugProject;

@end
