//
//  EventHandler.h
//  MMLInflater
//
//  Created by Lancelot on 2/16/15.
//  Copyright (c) 2015 Huawei. All rights reserved.
//

#import <MRuntime/MRuntime.h>
#import "MRViewController.h"

@interface Client : NSObject
@property (nonatomic, strong) NSInputStream* inputStream;
@property (nonatomic, strong) NSOutputStream* outputStream;
@end

@interface EventHandler : NSObject <NSNetServiceDelegate, NSStreamDelegate>

@property (nonatomic, assign) MRViewController* currentVC;
@property (nonatomic, strong) NSMutableData* data;

+(EventHandler*)getInstance :(MRViewController*)vc;

- (void)startServer;
- (void)connect;
- (NSData*)handleEvent:(NSString*)str;

@end
