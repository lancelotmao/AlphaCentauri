//
//  Menu.h
//  mWidget
//
//  Created by Lancelot on 2/27/15.
//  Copyright (c) 2015 huawei. All rights reserved.
//

#import <Foundation/Foundation.h>


#pragma mark MML Page Data

@interface MenuData : NSObject{
    NSMutableDictionary* attrs;
    NSMutableDictionary* events;
    NSString* type;
    NSMutableArray* children;
}
@property (nonatomic, strong) NSMutableDictionary* attrs;
@property (nonatomic, strong) NSMutableDictionary* events;
@property (nonatomic, strong) NSString* type;
@property (nonatomic, strong) NSMutableArray* children;
@end


@interface Menu : MenuData{

    NSMutableArray* menuArray;
}

@property (nonatomic, strong) NSMutableArray* menuArray;

@end
