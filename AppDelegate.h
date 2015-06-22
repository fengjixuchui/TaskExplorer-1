//
//  AppDelegate.h
//  KnockKnock
//
//  Created by Patrick Wardle
//  Copyright (c) 2015 Objective-See. All rights reserved.
//

#import "Binary.h"
#import "ItemBase.h"

#import "Filter.h"
#import "VirusTotal.h"
#import "TaskTableController.h"

#import "AboutWindowController.h"
#import "PrefsWindowController.h"
#import "ResultsWindowController.h"
#import "RequestRootWindowController.h"


#import "Task.h"
#import "TaskEnumerator.h"


#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate, NSWindowDelegate, NSTableViewDataSource, NSTableViewDelegate, NSMenuDelegate>
{
    //NSViewController *bottomViewController;

}

//'filter task' search box
// ->top pane
@property (weak) IBOutlet NSSearchField *filterTasksBox;


//(current) bottom view controller
@property(nonatomic, retain)TaskTableController *bottomViewController;

@property (weak) IBOutlet NSView *topPane;

//@property (weak) IBOutlet NSScrollView *taskScrollView;

//task enumerator object
@property(nonatomic, retain)TaskEnumerator* taskEnumerator;

//task table controller object
@property (nonatomic, retain)TaskTableController *taskTableController;


//current task view format
// ->flat or tree
@property NSUInteger taskViewFormat;

//drop-down view selector

@property (weak) IBOutlet NSPopUpButton *viewSelector;

//segmented button for button pane
// ->select to view dylib, files, network, etc
@property (weak) IBOutlet NSSegmentedControl *bottomPaneBtn;

//action when segmented button is clicked
-(IBAction)selectBottomPaneContent:(id)sender;

//bottom pane view
@property (weak) IBOutlet NSView *bottomPane;


//'filter items' search box
// ->bottom pane
@property (weak) IBOutlet NSSearchField *filterItemsBox;

@property (assign) IBOutlet NSWindow *window;

@property (weak) IBOutlet NSButton *logoButton;


@property (weak) IBOutlet NSButton *showPreferencesButton;

//spinner
@property (weak) IBOutlet NSProgressIndicator *progressIndicator;

//status msg
@property (weak) IBOutlet NSTextField *statusText;

//non-UI thread that performs actual scan
@property(nonatomic, strong)NSThread *scannerThread;

//filter object
@property(nonatomic, retain)Filter* filterObj;

//virus total object
@property(nonatomic, retain)VirusTotal* virusTotalObj;

//array for all virus total threads
@property(nonatomic, retain)NSMutableArray* vtThreads;

//request root window controller
@property(nonatomic, retain)RequestRootWindowController* requestRootWindowController;

//preferences window controller
@property(nonatomic, retain)PrefsWindowController* prefsWindowController;

//about window controller
@property(nonatomic, retain)AboutWindowController* aboutWindowController;

//results window controller
@property(nonatomic, retain)ResultsWindowController* resultsWindowController;

//currently selected task
@property(nonatomic, retain)Task* currentTask;

//activity indicator for bottom pane
@property (weak) IBOutlet NSProgressIndicator *bottomPaneSpinner;

//'no items' found label for bottom pane
@property (weak) IBOutlet NSTextField *noItemsLabel;

/* METHODS */
- (IBAction)switchView:(id)sender;

//init tracking areas for buttons
// ->provide mouse over effects
-(void)initTrackingAreas;

//callback method, invoked by virus total when plugin's items have been processed
// ->reload table if plugin matches active plugin
//-(void)itemsProcessed:(PluginBase*)plugin;


//callback when user has updated prefs
// ->reload table, etc
-(void)applyPreferences;

//update a single row
-(void)itemProcessed:(Binary*)fileObj rowIndex:(NSUInteger)rowIndex;

//action
// ->invoked when user clicks 'About/Info' or Objective-See logo in main UI
-(void)displayScanStats;

-(IBAction)scanButtonHandler:(id)sender;

//button handler for when settings icon (gear) is clicked
-(IBAction)showPreferences:(id)sender;

//kickoff a thread to query VT
//-(void)queryVT:(PluginBase*)plugin;

//button handler for logo
-(IBAction)logoButtonHandler:(id)sender;

//action for 'about' in menu/logo in UI
-(IBAction)about:(id)sender;

//TODO add this, and move into properties
//version string
@property (weak) IBOutlet NSTextField *versionString;

//reload (to re-draw) a specific row in table
-(void)reloadRow:(Task*)task item:(ItemBase*)item pane:(NSUInteger)pane;

//reload task table
-(void)reloadTaskTable;

//smartly, reload bottom pane
// ->checks if task & item type (e.g. files) are both selected
-(void)reloadBottomPane:(Task*)task itemView:(NSUInteger)itemView;

//begin task enumeration
-(void)exploreTasks;

//sort tasks
// ->either name (flat view) or pid (tree view)
-(void)sortTasksForView:(OrderedDictionary*)tasks;

//filter tasks
-(void)filterTasks:(NSString*)filterText;


@end
