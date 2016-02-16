//
//  MRLocation.h
//  MRLBSBundle
//
//  Created by mCloud on 15/1/9.
//  Copyright (c) 2015年 mCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <JavaScriptCore/JavaScriptCore.h>

@interface MRLocation : NSObject <CLLocationManagerDelegate>

- (void)startLocationForJS:(NSNumber *)accuracy :(JSValue *)cb;
- (void)stopLocationForJS:(JSValue *)cb;
- (void)getLocationOnceForJS:(NSNumber *)accuracy :(JSValue *)cb;

- (void)startLocation:(NSNumber *)accuracy :(void(^)(NSDictionary *))cb;
- (void)getLocationOnce:(NSNumber *)accuracy :(void(^)(NSDictionary *))cb;
- (void)stopLocation;

@end
