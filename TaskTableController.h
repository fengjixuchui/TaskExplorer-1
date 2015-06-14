//
//  ItemTableController.h
//  KnockKnock
//
//  Created by Patrick Wardle on 2/18/15.
//  Copyright (c) 2015 Objective-See. All rights reserved.
//

#import "Task.h"
#import "InfoWindowController.h"
#import "VTInfoWindowController.h"
#import "3rdParty/OrderedDictionary.h"



#import <Foundation/Foundation.h>

@interface TaskTableController : NSViewController <NSTableViewDataSource, NSTableViewDelegate>
{
    
}

//tasks
// ->updated by task enumerator
//@property(nonatomic, retain)OrderedDictionary* tasks;

@property(nonatomic, retain)NSMutableArray* tableItems;

//category table view
@property(weak) IBOutlet NSTableView *itemView;

//info window
@property(retain, nonatomic)InfoWindowController* infoWindowController;

//preferences window controller
@property (nonatomic, retain)VTInfoWindowController* vtWindowController;

//currently selected row
// ->can help determine if newly selected row is really new
@property NSUInteger selectedRow;

//flag to differentiate between top/bottom view
@property BOOL isBottomPane;

/* METHODS */

//reload table
-(void)reloadTable;

//custom reload
// ->ensures selected row remains selected
-(void)refresh;

//grab a task at a row
-(Task*)taskForRow:(id)sender;

//button handler
// ->show item in finder
- (IBAction)showInFinder:(id)sender;

//button handler
// ->show info window
- (IBAction)showInfo:(id)sender;

//button handler
// ->show virus total info window
-(void)showVTInfo:(NSView*)button;

//scroll back up to top of table
-(void)scrollToTop;

//helper function
// ->get items array (either all or just unknown)
-(NSArray*)getTableItems;

//determine if instance is rendering top pane
// ->for now, just looks at 'tableItems' iVar
-(BOOL)isTopPane;


@end
