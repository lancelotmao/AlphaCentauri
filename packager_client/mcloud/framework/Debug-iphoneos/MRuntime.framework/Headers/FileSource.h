//
//  FileSource.h
//  MMLInflater
//
//  Created by mCloud on 15/1/15.
//  Copyright (c) 2015年 Huawei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MMLFileSource : NSObject

-(NSString*) getBaseFolder;
-(NSData*) getFileContent:(NSString*)filePath ofType:(NSString*)type;
-(NSData *)getProjectFileContent:(NSString*)filePath ofType:(NSString*)type;

@property (strong) NSString* projectName;

@end


@interface PresetFileSource : MMLFileSource
@end

@interface ProjectFileSource : MMLFileSource
-(instancetype)initWithProjectName:(NSString*)name;
@end
