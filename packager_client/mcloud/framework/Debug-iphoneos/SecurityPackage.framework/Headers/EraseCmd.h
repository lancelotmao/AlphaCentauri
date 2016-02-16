//
//  EraseCmd.h
//  test_json
//
//  Created by mcloud-mac on 15/6/27.
//  Copyright (c) 2015年 mcloud-mac. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EraseCmd : NSObject

{
@public
    NSString                *strUser;
    NSString                *strDevId;
    NSString                *strCmdId;
    NSString                *strAction;
    NSString                *strActionObj;
}

typedef enum{
    
    EraseTypeNone = 0,              // 无类型
    EraseTypeAll,                   // 所有数据
    EraseTypePrivCert,              // 所有证书
    EraseTypePrivData               // 个人数据
    
} EraseType;

/**************************************************************/
// 解析擦除命令
// 参数:
//			dataErase-[IN]命令
// 返回值: YES-成功，NO-失败
/**************************************************************/
- (BOOL)ParseCmd:(NSDictionary *)dataErase;

/**************************************************************/
// 保存擦除命令
// 参数:
// 返回值: YES-成功，NO-失败
/**************************************************************/
- (BOOL)SaveCmd;

/**************************************************************/
// 擦除指令是否存在
// 参数:
//			strUser-[OUT]保存用户名
// 返回值: 擦除类型
/**************************************************************/
+ (EraseType)IsEraseActionExist:(NSString **)strUser;

/**************************************************************/
// 清除命令
// 参数:
// 返回值:
/**************************************************************/
+ (void)CleanCmd;

@end



 