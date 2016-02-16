//
//  MMLActionParser.h
//  MMLInflater
//
//  Created by mCloud on 15/1/12.
//  Copyright (c) 2015年 Huawei. All rights reserved.
//

#import <MRuntime/MRuntime.h>
#import "MMLData.h"
#import "MMLData.h"

@interface MMLActionParser : NSObject

-(MMLActionData*) parseFile:(NSString*) actionFile withFileSource:(MMLFileSource*)fileSource;
-(MMLActionData*) parseData:(NSData*) data;

@end
