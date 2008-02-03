require File.dirname(__FILE__) + '/../../../spec_helper'
require File.dirname(__FILE__) + '/../../../runner/guards/bug'

describe Object, "#ruby_bug" do
  before :each do
    @guard = BugGuard.new
    BugGuard.stub!(:new).and_return(@guard)
  end
  
  it "yields when the implementation is not :ruby" do
    @guard.stub!(:implementation?).and_return(false)
    ruby_bug { @record = :yield }
    @record.should == :yield
  end
  
  it "does not yield when the implementation is :ruby" do
    @guard.stub!(:implementation?).and_return(true)
    ruby_bug { @record = :yield }
    @record.should_not == :yield
  end
end
