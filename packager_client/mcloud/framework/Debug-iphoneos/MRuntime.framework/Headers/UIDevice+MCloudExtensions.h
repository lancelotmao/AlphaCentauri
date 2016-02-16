//
//  UIDevice+MCloudExtensions.h
//  MRuntime
//
//  Created by rossyang on 15/4/16.
//  Copyright (c) 2015年 huawei. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, mCloudDeviceType) {
    DeviceAppleUnknown,
    DeviceAppleSimulator,
    DeviceAppleiPhone,
    DeviceAppleiPhone3G,
    DeviceAppleiPhone3GS,
    DeviceAppleiPhone4,
    DeviceAppleiPhone4S,
    DeviceAppleiPhone5,
    DeviceAppleiPhone5C,
    DeviceAppleiPhone5S,
    DeviceAppleiPhone6,
    DeviceAppleiPhone6_Plus,
    DeviceAppleiPodTouch,
    DeviceAppleiPodTouch2G,
    DeviceAppleiPodTouch3G,
    DeviceAppleiPodTouch4G,
    DeviceAppleiPad,
    DeviceAppleiPad2,
    DeviceAppleiPad3G,
    DeviceAppleiPad4G,
    DeviceAppleiPad5G_Air,
    DeviceAppleiPadMini,
    DeviceAppleiPadMini2G
};


@interface UIDevice (MCloudExtensions)
- (NSString *) mcloud_deviceDescription;
- (mCloudDeviceType) mcloud_deviceType;

@end
