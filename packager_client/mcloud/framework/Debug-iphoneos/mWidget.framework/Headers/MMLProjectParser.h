//
//  MMLProjectParser.h
//  MMLInflater
//
//  Created by mCloud on 15/1/12.
//  Copyright (c) 2015年 Huawei. All rights reserved.
//

#import <MRuntime/MRuntime.h>
#import "MMLData.h"

@interface MMLProjectParser : NSObject

-(MMLProjectData*) parseFile:(NSString*) projectFile withFileSource:(MMLFileSource*)fileSource;

@end
