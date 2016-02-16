//
//  MMLParser.h
//  mWidget
//
//  Created by mCloud on 14/12/23.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import <MRuntime/MRuntime.h>
#import "MMLData.h"

@interface MMLParser : NSObject{
    TBXML *golbleXml;
}

-(MMLData*) parseFile:(NSString*) mmlFile withFileSource:(MMLFileSource*)fileSource;
-(MMLData*) parseString:(NSString*) pgStr :(NSString*)actStr;
-(MMLData*) parseData:(NSData*) pgData :(NSData*)actData;
@end
