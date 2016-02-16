//
//  MMLData.h
//  mWidget
//
//  Created by mCloud on 14/12/23.
//  Copyright (c) 2014年 mCloud. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark MML Project Data
@interface MMLProjectData : NSObject
@property (nonatomic) NSString* projectId;
@property (nonatomic) NSString* name;
@property (nonatomic) NSString* startPage;
@property (nonatomic) NSString* versionName;
@property (nonatomic) NSInteger versionCode;
@property (nonatomic) NSString *versionString;
@property (nonatomic) NSString *appOrientation;
@end

#pragma mark MML Action Data
@interface MMLActionData : NSObject
@property (nonatomic) NSMutableArray* importList;
@property (nonatomic) NSMutableDictionary* handlers;
@property (nonatomic) NSString* globalScript;
@end


#pragma mark MML Page Data

@interface MMLViewData : NSObject
@property (nonatomic, readonly) NSMutableDictionary* attrs;
@property (nonatomic) NSMutableDictionary* events;
 //ns1, attr1, value1, ns2, attr2, value2...
@property (nonatomic, readonly) NSMutableArray* namespacedAttrs;
@property (nonatomic) NSString* type;
@property (nonatomic) NSMutableArray* children;
@end

@interface MMLListData : MMLViewData
@property (nonatomic) NSMutableArray* contextMenu;
@property (nonatomic) NSMutableArray* itemTemplates;
@property (nonatomic) NSMutableArray* sectionTemplates;
@property (nonatomic) NSMutableArray* footers;
@property (nonatomic) NSMutableArray* menuItem;
@property (nonatomic) MMLViewData *headerView;
@end

@interface MMLData : NSObject
@property (nonatomic) MMLViewData* pageData;
@property (nonatomic) MMLViewData* rootView;
@property (nonatomic) MMLViewData* actionBar;
@property (nonatomic) MMLActionData* actionData;

-(BOOL) writeToFile:(NSString*)file;
+(MMLData*) mmlWithContentsOfFile:(NSString*)file;
@end

