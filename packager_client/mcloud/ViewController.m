//
//  ViewController.m
//  ICD
//
//  Created by Lance Mao on 6/10/15.
//  Copyright (c) 2015 Hua Wei. All rights reserved.
//

#import "ViewController.h"
#import <MRuntime/MRuntime.h>
#import <mWidget/mWidget.h>


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self loadMMLProject];
    NSString *startPage = [self getStartPage];
    MRViewController *vc = [MMLVCFactory createVCFromFile:nil :startPage :@"MMLProject"];
    [self.navigationController pushViewController:vc animated:NO];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

//MML工程默认名字都为MMLProject.zip
- (void)loadMMLProject {
    BOOL isFistLogin = [[[NSUserDefaults standardUserDefaults] objectForKey:@"FIRSTLOGIN"] boolValue];
    if (isFistLogin) {
        return;
    }
    NSString *mmlProjectZipFile = [[NSBundle mainBundle] pathForResource:@"MMLProject" ofType:@"zip"];
    NSString *documentPath = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
    NSString *filePath = [NSString stringWithFormat:@"%@/Projects/%@", documentPath, @"MMLProject"];
    NSFileManager *manager = [NSFileManager defaultManager];
    if (![manager fileExistsAtPath:filePath]) {
        [manager createDirectoryAtPath:filePath withIntermediateDirectories:YES attributes:nil error:nil];
    }
    
    
    
    [MRZipArchive unzipFileAtPath:mmlProjectZipFile toDestination:filePath];
    //[manager removeItemAtPath:mmlProjectZipFile error:nil];

    [ResourceManager preprocessingImage:filePath];
    [[NSUserDefaults standardUserDefaults] setObject:@YES forKey:@"FIRSTLOGIN"];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (NSString*)getStartPage {
    NSString *startPage = nil;
    MMLFileSource* fileSource = [[ProjectFileSource alloc] initWithProjectName:@"MMLProject"];
    MMLProjectData *projectData = [[[MMLProjectParser alloc] init] parseFile:@"projectconfig" withFileSource:fileSource];
    if (projectData) {
        startPage = projectData.startPage;
    }

    return startPage;
}
@end
