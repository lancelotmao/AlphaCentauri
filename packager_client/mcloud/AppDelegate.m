//
//  AppDelegate.m
//  ICD
//
//  Created by Lance Mao on 6/10/15.
//  Copyright (c) 2015 Hua Wei. All rights reserved.
//

#import "AppDelegate.h"
#import "ViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [super application:application didFinishLaunchingWithOptions:launchOptions];
    self.autoUpgradeBundle = NO;
    // self.shakeToUpdate = NO;
    //[self startProject];
    [self loadBuiltInBundles];
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    [self.window setBackgroundColor:[UIColor whiteColor]];
    ViewController *vc = [ViewController new];
    
    MRContext *context = [[MRContext alloc] init];
    context.delegate = [MRBundleManager shareInstance];
    [MRBusAccess shareInstance].context = context; 
    [[LogManager sharedInstance] setEnableFileLog:YES];

    //record BigDataLog
    NSString *bundleIdentifier = [[[NSBundle mainBundle] infoDictionary]  objectForKey:(id)kCFBundleNameKey];
    NSDictionary *configurations = @{@"app_id": bundleIdentifier};
    [[LogManager sharedInstance] setupBigData:configurations];
    [[LogManager sharedInstance] logBigData:@"action=launch" packageName:bundleIdentifier];

    
     

    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
    nav.navigationBar.translucent = NO;
    [self.window setRootViewController:nav];
    [self.window makeKeyAndVisible];
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
    [super applicationWillResignActive:application];
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    [super applicationDidEnterBackground:application];
    NSString *bundleIdentifier = [[[NSBundle mainBundle] infoDictionary]  objectForKey:(id)kCFBundleNameKey];
    [[LogManager sharedInstance] logBigData:@"action=background" packageName:bundleIdentifier];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    [super applicationWillEnterForeground:application];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    [super applicationDidBecomeActive:application];
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    [super applicationWillTerminate:application];
    NSString *bundleIdentifier = [[[NSBundle mainBundle] infoDictionary]  objectForKey:(id)kCFBundleNameKey];
    [[LogManager sharedInstance] logBigData:@"action=terminate" packageName:bundleIdentifier];
}

@end
