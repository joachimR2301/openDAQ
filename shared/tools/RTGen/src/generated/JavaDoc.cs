//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     ANTLR Version: 4.11.1
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from F:/Dewesoft/C++/git/Blueberry3/shared/tools/RTGen/src\JavaDoc.g4 by ANTLR 4.11.1

// Unreachable code detected
#pragma warning disable 0162
// The variable '...' is assigned but its value is never used
#pragma warning disable 0219
// Missing XML comment for publicly visible type or member '...'
#pragma warning disable 1591
// Ambiguous reference in cref attribute
#pragma warning disable 419

using System;
using System.IO;
using System.Text;
using System.Diagnostics;
using System.Collections.Generic;
using Antlr4.Runtime;
using Antlr4.Runtime.Atn;
using Antlr4.Runtime.Misc;
using Antlr4.Runtime.Tree;
using DFA = Antlr4.Runtime.Dfa.DFA;

[System.CodeDom.Compiler.GeneratedCode("ANTLR", "4.11.1")]
[System.CLSCompliant(false)]
public partial class JavaDoc : Parser {
	protected static DFA[] decisionToDFA;
	protected static PredictionContextCache sharedContextCache = new PredictionContextCache();
	public const int
		AtSign=1, LBrace=2, RBrace=3, LBracket=4, RBracket=5, DocStartSection=6, 
		DocEndSection=7, DocCode=8, DocEndCode=9, DocStartCode=10, DocPrivate=11, 
		DocRetVal=12, DocParam=13, DocBrief=14, DocThrows=15, DocParamRef=16, 
		DocCodeRef=17, DocAttribute=18, DocWord=19, WS=20, NL=21, Star=22, DocStart=23, 
		DocEnd=24;
	public const int
		RULE_start = 0, RULE_descrptionWihoutTag = 1, RULE_docBlock = 2, RULE_attributes = 3, 
		RULE_attribute = 4, RULE_attributeInline = 5, RULE_docLine = 6, RULE_docParagraph = 7;
	public static readonly string[] ruleNames = {
		"start", "descrptionWihoutTag", "docBlock", "attributes", "attribute", 
		"attributeInline", "docLine", "docParagraph"
	};

	private static readonly string[] _LiteralNames = {
		null, "'@'", "'{'", "'}'", "'['", "']'", "'@{'", "'@}'", null, null, null, 
		null, null, null, null, null, null, null, null, null, null, null, "'*'", 
		"'/*!'", "'*/'"
	};
	private static readonly string[] _SymbolicNames = {
		null, "AtSign", "LBrace", "RBrace", "LBracket", "RBracket", "DocStartSection", 
		"DocEndSection", "DocCode", "DocEndCode", "DocStartCode", "DocPrivate", 
		"DocRetVal", "DocParam", "DocBrief", "DocThrows", "DocParamRef", "DocCodeRef", 
		"DocAttribute", "DocWord", "WS", "NL", "Star", "DocStart", "DocEnd"
	};
	public static readonly IVocabulary DefaultVocabulary = new Vocabulary(_LiteralNames, _SymbolicNames);

	[NotNull]
	public override IVocabulary Vocabulary
	{
		get
		{
			return DefaultVocabulary;
		}
	}

	public override string GrammarFileName { get { return "JavaDoc.g4"; } }

	public override string[] RuleNames { get { return ruleNames; } }

	public override int[] SerializedAtn { get { return _serializedATN; } }

	static JavaDoc() {
		decisionToDFA = new DFA[_ATN.NumberOfDecisions];
		for (int i = 0; i < _ATN.NumberOfDecisions; i++) {
			decisionToDFA[i] = new DFA(_ATN.GetDecisionState(i), i);
		}
	}

		public JavaDoc(ITokenStream input) : this(input, Console.Out, Console.Error) { }

		public JavaDoc(ITokenStream input, TextWriter output, TextWriter errorOutput)
		: base(input, output, errorOutput)
	{
		Interpreter = new ParserATNSimulator(this, _ATN, decisionToDFA, sharedContextCache);
	}

	public partial class StartContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocStart() { return GetToken(JavaDoc.DocStart, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public AttributesContext attributes() {
			return GetRuleContext<AttributesContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocEnd() { return GetToken(JavaDoc.DocEnd, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Eof() { return GetToken(JavaDoc.Eof, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode[] NL() { return GetTokens(JavaDoc.NL); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode NL(int i) {
			return GetToken(JavaDoc.NL, i);
		}
		[System.Diagnostics.DebuggerNonUserCode] public DescrptionWihoutTagContext descrptionWihoutTag() {
			return GetRuleContext<DescrptionWihoutTagContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode[] Star() { return GetTokens(JavaDoc.Star); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Star(int i) {
			return GetToken(JavaDoc.Star, i);
		}
		public StartContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_start; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterStart(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitStart(this);
		}
	}

	[RuleVersion(0)]
	public StartContext start() {
		StartContext _localctx = new StartContext(Context, State);
		EnterRule(_localctx, 0, RULE_start);
		int _la;
		try {
			EnterOuterAlt(_localctx, 1);
			{
			State = 16;
			Match(DocStart);
			State = 18;
			ErrorHandler.Sync(this);
			_la = TokenStream.LA(1);
			if (_la==NL) {
				{
				State = 17;
				Match(NL);
				}
			}

			State = 21;
			ErrorHandler.Sync(this);
			switch ( Interpreter.AdaptivePredict(TokenStream,1,Context) ) {
			case 1:
				{
				State = 20;
				descrptionWihoutTag();
				}
				break;
			}
			State = 23;
			attributes();
			State = 28;
			ErrorHandler.Sync(this);
			_la = TokenStream.LA(1);
			while (_la==Star) {
				{
				{
				State = 24;
				Match(Star);
				State = 25;
				Match(NL);
				}
				}
				State = 30;
				ErrorHandler.Sync(this);
				_la = TokenStream.LA(1);
			}
			State = 31;
			Match(DocEnd);
			State = 32;
			Match(Eof);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class DescrptionWihoutTagContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public DocParagraphContext docParagraph() {
			return GetRuleContext<DocParagraphContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Star() { return GetToken(JavaDoc.Star, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode NL() { return GetToken(JavaDoc.NL, 0); }
		public DescrptionWihoutTagContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_descrptionWihoutTag; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDescrptionWihoutTag(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDescrptionWihoutTag(this);
		}
	}

	[RuleVersion(0)]
	public DescrptionWihoutTagContext descrptionWihoutTag() {
		DescrptionWihoutTagContext _localctx = new DescrptionWihoutTagContext(Context, State);
		EnterRule(_localctx, 2, RULE_descrptionWihoutTag);
		int _la;
		try {
			EnterOuterAlt(_localctx, 1);
			{
			State = 35;
			ErrorHandler.Sync(this);
			_la = TokenStream.LA(1);
			if (_la==Star) {
				{
				State = 34;
				Match(Star);
				}
			}

			State = 37;
			docParagraph();
			State = 39;
			ErrorHandler.Sync(this);
			_la = TokenStream.LA(1);
			if (_la==NL) {
				{
				State = 38;
				Match(NL);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class DocBlockContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocStartSection() { return GetToken(JavaDoc.DocStartSection, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocEndSection() { return GetToken(JavaDoc.DocEndSection, 0); }
		public DocBlockContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_docBlock; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocBlock(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocBlock(this);
		}
	}

	[RuleVersion(0)]
	public DocBlockContext docBlock() {
		DocBlockContext _localctx = new DocBlockContext(Context, State);
		EnterRule(_localctx, 4, RULE_docBlock);
		int _la;
		try {
			EnterOuterAlt(_localctx, 1);
			{
			State = 41;
			_la = TokenStream.LA(1);
			if ( !(_la==DocStartSection || _la==DocEndSection) ) {
			ErrorHandler.RecoverInline(this);
			}
			else {
				ErrorHandler.ReportMatch(this);
			    Consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class AttributesContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public AttributeContext[] attribute() {
			return GetRuleContexts<AttributeContext>();
		}
		[System.Diagnostics.DebuggerNonUserCode] public AttributeContext attribute(int i) {
			return GetRuleContext<AttributeContext>(i);
		}
		public AttributesContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_attributes; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterAttributes(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitAttributes(this);
		}
	}

	[RuleVersion(0)]
	public AttributesContext attributes() {
		AttributesContext _localctx = new AttributesContext(Context, State);
		EnterRule(_localctx, 6, RULE_attributes);
		try {
			int _alt;
			EnterOuterAlt(_localctx, 1);
			{
			State = 46;
			ErrorHandler.Sync(this);
			_alt = Interpreter.AdaptivePredict(TokenStream,5,Context);
			while ( _alt!=2 && _alt!=global::Antlr4.Runtime.Atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					State = 43;
					attribute();
					}
					} 
				}
				State = 48;
				ErrorHandler.Sync(this);
				_alt = Interpreter.AdaptivePredict(TokenStream,5,Context);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class AttributeContext : ParserRuleContext {
		public AttributeContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_attribute; } }
	 
		public AttributeContext() { }
		public virtual void CopyFrom(AttributeContext context) {
			base.CopyFrom(context);
		}
	}
	public partial class DocBlockRawContext : AttributeContext {
		[System.Diagnostics.DebuggerNonUserCode] public DocBlockContext docBlock() {
			return GetRuleContext<DocBlockContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Star() { return GetToken(JavaDoc.Star, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode NL() { return GetToken(JavaDoc.NL, 0); }
		public DocBlockRawContext(AttributeContext context) { CopyFrom(context); }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocBlockRaw(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocBlockRaw(this);
		}
	}
	public partial class DocAttributeContext : AttributeContext {
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode[] Star() { return GetTokens(JavaDoc.Star); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Star(int i) {
			return GetToken(JavaDoc.Star, i);
		}
		[System.Diagnostics.DebuggerNonUserCode] public AttributeInlineContext attributeInline() {
			return GetRuleContext<AttributeInlineContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode[] NL() { return GetTokens(JavaDoc.NL); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode NL(int i) {
			return GetToken(JavaDoc.NL, i);
		}
		public DocAttributeContext(AttributeContext context) { CopyFrom(context); }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocAttribute(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocAttribute(this);
		}
	}
	public partial class DocDescriptionContext : AttributeContext {
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode[] Star() { return GetTokens(JavaDoc.Star); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Star(int i) {
			return GetToken(JavaDoc.Star, i);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode[] NL() { return GetTokens(JavaDoc.NL); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode NL(int i) {
			return GetToken(JavaDoc.NL, i);
		}
		[System.Diagnostics.DebuggerNonUserCode] public DocParagraphContext docParagraph() {
			return GetRuleContext<DocParagraphContext>(0);
		}
		public DocDescriptionContext(AttributeContext context) { CopyFrom(context); }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocDescription(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocDescription(this);
		}
	}

	[RuleVersion(0)]
	public AttributeContext attribute() {
		AttributeContext _localctx = new AttributeContext(Context, State);
		EnterRule(_localctx, 8, RULE_attribute);
		int _la;
		try {
			State = 70;
			ErrorHandler.Sync(this);
			switch ( Interpreter.AdaptivePredict(TokenStream,9,Context) ) {
			case 1:
				_localctx = new DocDescriptionContext(_localctx);
				EnterOuterAlt(_localctx, 1);
				{
				State = 49;
				Match(Star);
				State = 50;
				Match(NL);
				State = 51;
				Match(Star);
				State = 52;
				docParagraph();
				State = 53;
				Match(NL);
				}
				break;
			case 2:
				_localctx = new DocAttributeContext(_localctx);
				EnterOuterAlt(_localctx, 2);
				{
				State = 55;
				Match(Star);
				State = 58;
				ErrorHandler.Sync(this);
				_la = TokenStream.LA(1);
				if (_la==NL) {
					{
					State = 56;
					Match(NL);
					State = 57;
					Match(Star);
					}
				}

				State = 60;
				attributeInline();
				State = 61;
				Match(NL);
				}
				break;
			case 3:
				_localctx = new DocBlockRawContext(_localctx);
				EnterOuterAlt(_localctx, 3);
				{
				State = 64;
				ErrorHandler.Sync(this);
				_la = TokenStream.LA(1);
				if (_la==Star) {
					{
					State = 63;
					Match(Star);
					}
				}

				State = 66;
				docBlock();
				State = 68;
				ErrorHandler.Sync(this);
				_la = TokenStream.LA(1);
				if (_la==NL) {
					{
					State = 67;
					Match(NL);
					}
				}

				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class AttributeInlineContext : ParserRuleContext {
		public AttributeInlineContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_attributeInline; } }
	 
		public AttributeInlineContext() { }
		public virtual void CopyFrom(AttributeInlineContext context) {
			base.CopyFrom(context);
		}
	}
	public partial class DocCodeRefContext : AttributeInlineContext {
		public IToken codeWord;
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocCodeRef() { return GetToken(JavaDoc.DocCodeRef, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocWord() { return GetToken(JavaDoc.DocWord, 0); }
		public DocCodeRefContext(AttributeInlineContext context) { CopyFrom(context); }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocCodeRef(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocCodeRef(this);
		}
	}
	public partial class DocCodeContext : AttributeInlineContext {
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocStartCode() { return GetToken(JavaDoc.DocStartCode, 0); }
		public DocCodeContext(AttributeInlineContext context) { CopyFrom(context); }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocCode(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocCode(this);
		}
	}
	public partial class DocRetValContext : AttributeInlineContext {
		public IToken errCode;
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocRetVal() { return GetToken(JavaDoc.DocRetVal, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public DocParagraphContext docParagraph() {
			return GetRuleContext<DocParagraphContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocWord() { return GetToken(JavaDoc.DocWord, 0); }
		public DocRetValContext(AttributeInlineContext context) { CopyFrom(context); }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocRetVal(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocRetVal(this);
		}
	}
	public partial class DocParamRefContext : AttributeInlineContext {
		public IToken paramRef;
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocParamRef() { return GetToken(JavaDoc.DocParamRef, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocWord() { return GetToken(JavaDoc.DocWord, 0); }
		public DocParamRefContext(AttributeInlineContext context) { CopyFrom(context); }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocParamRef(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocParamRef(this);
		}
	}
	public partial class DocPrivateContext : AttributeInlineContext {
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocPrivate() { return GetToken(JavaDoc.DocPrivate, 0); }
		public DocPrivateContext(AttributeInlineContext context) { CopyFrom(context); }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocPrivate(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocPrivate(this);
		}
	}
	public partial class DocBriefContext : AttributeInlineContext {
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocBrief() { return GetToken(JavaDoc.DocBrief, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public DocParagraphContext docParagraph() {
			return GetRuleContext<DocParagraphContext>(0);
		}
		public DocBriefContext(AttributeInlineContext context) { CopyFrom(context); }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocBrief(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocBrief(this);
		}
	}
	public partial class DocThrowsContext : AttributeInlineContext {
		public IToken exceptionName;
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocThrows() { return GetToken(JavaDoc.DocThrows, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public DocParagraphContext docParagraph() {
			return GetRuleContext<DocParagraphContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocWord() { return GetToken(JavaDoc.DocWord, 0); }
		public DocThrowsContext(AttributeInlineContext context) { CopyFrom(context); }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocThrows(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocThrows(this);
		}
	}
	public partial class DocGenericContext : AttributeInlineContext {
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocAttribute() { return GetToken(JavaDoc.DocAttribute, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public DocParagraphContext docParagraph() {
			return GetRuleContext<DocParagraphContext>(0);
		}
		public DocGenericContext(AttributeInlineContext context) { CopyFrom(context); }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocGeneric(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocGeneric(this);
		}
	}
	public partial class DocParamContext : AttributeInlineContext {
		public IToken paramName;
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocParam() { return GetToken(JavaDoc.DocParam, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public DocParagraphContext docParagraph() {
			return GetRuleContext<DocParagraphContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocWord() { return GetToken(JavaDoc.DocWord, 0); }
		public DocParamContext(AttributeInlineContext context) { CopyFrom(context); }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocParam(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocParam(this);
		}
	}

	[RuleVersion(0)]
	public AttributeInlineContext attributeInline() {
		AttributeInlineContext _localctx = new AttributeInlineContext(Context, State);
		EnterRule(_localctx, 10, RULE_attributeInline);
		try {
			State = 91;
			ErrorHandler.Sync(this);
			switch (TokenStream.LA(1)) {
			case DocBrief:
				_localctx = new DocBriefContext(_localctx);
				EnterOuterAlt(_localctx, 1);
				{
				State = 72;
				Match(DocBrief);
				State = 73;
				docParagraph();
				}
				break;
			case DocThrows:
				_localctx = new DocThrowsContext(_localctx);
				EnterOuterAlt(_localctx, 2);
				{
				State = 74;
				Match(DocThrows);
				State = 75;
				((DocThrowsContext)_localctx).exceptionName = Match(DocWord);
				State = 76;
				docParagraph();
				}
				break;
			case DocParam:
				_localctx = new DocParamContext(_localctx);
				EnterOuterAlt(_localctx, 3);
				{
				State = 77;
				Match(DocParam);
				State = 78;
				((DocParamContext)_localctx).paramName = Match(DocWord);
				State = 79;
				docParagraph();
				}
				break;
			case DocParamRef:
				_localctx = new DocParamRefContext(_localctx);
				EnterOuterAlt(_localctx, 4);
				{
				State = 80;
				Match(DocParamRef);
				State = 81;
				((DocParamRefContext)_localctx).paramRef = Match(DocWord);
				}
				break;
			case DocRetVal:
				_localctx = new DocRetValContext(_localctx);
				EnterOuterAlt(_localctx, 5);
				{
				State = 82;
				Match(DocRetVal);
				State = 83;
				((DocRetValContext)_localctx).errCode = Match(DocWord);
				State = 84;
				docParagraph();
				}
				break;
			case DocPrivate:
				_localctx = new DocPrivateContext(_localctx);
				EnterOuterAlt(_localctx, 6);
				{
				State = 85;
				Match(DocPrivate);
				}
				break;
			case DocCodeRef:
				_localctx = new DocCodeRefContext(_localctx);
				EnterOuterAlt(_localctx, 7);
				{
				State = 86;
				Match(DocCodeRef);
				State = 87;
				((DocCodeRefContext)_localctx).codeWord = Match(DocWord);
				}
				break;
			case DocAttribute:
				_localctx = new DocGenericContext(_localctx);
				EnterOuterAlt(_localctx, 8);
				{
				State = 88;
				Match(DocAttribute);
				State = 89;
				docParagraph();
				}
				break;
			case DocStartCode:
				_localctx = new DocCodeContext(_localctx);
				EnterOuterAlt(_localctx, 9);
				{
				State = 90;
				Match(DocStartCode);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class DocLineContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode[] DocWord() { return GetTokens(JavaDoc.DocWord); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode DocWord(int i) {
			return GetToken(JavaDoc.DocWord, i);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode[] Star() { return GetTokens(JavaDoc.Star); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Star(int i) {
			return GetToken(JavaDoc.Star, i);
		}
		[System.Diagnostics.DebuggerNonUserCode] public AttributeInlineContext[] attributeInline() {
			return GetRuleContexts<AttributeInlineContext>();
		}
		[System.Diagnostics.DebuggerNonUserCode] public AttributeInlineContext attributeInline(int i) {
			return GetRuleContext<AttributeInlineContext>(i);
		}
		public DocLineContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_docLine; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocLine(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocLine(this);
		}
	}

	[RuleVersion(0)]
	public DocLineContext docLine() {
		DocLineContext _localctx = new DocLineContext(Context, State);
		EnterRule(_localctx, 12, RULE_docLine);
		try {
			int _alt;
			EnterOuterAlt(_localctx, 1);
			{
			State = 93;
			Match(DocWord);
			State = 99;
			ErrorHandler.Sync(this);
			_alt = Interpreter.AdaptivePredict(TokenStream,12,Context);
			while ( _alt!=2 && _alt!=global::Antlr4.Runtime.Atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					State = 97;
					ErrorHandler.Sync(this);
					switch (TokenStream.LA(1)) {
					case DocWord:
						{
						State = 94;
						Match(DocWord);
						}
						break;
					case Star:
						{
						State = 95;
						Match(Star);
						}
						break;
					case DocStartCode:
					case DocPrivate:
					case DocRetVal:
					case DocParam:
					case DocBrief:
					case DocThrows:
					case DocParamRef:
					case DocCodeRef:
					case DocAttribute:
						{
						State = 96;
						attributeInline();
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					} 
				}
				State = 101;
				ErrorHandler.Sync(this);
				_alt = Interpreter.AdaptivePredict(TokenStream,12,Context);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	public partial class DocParagraphContext : ParserRuleContext {
		[System.Diagnostics.DebuggerNonUserCode] public DocLineContext docLine() {
			return GetRuleContext<DocLineContext>(0);
		}
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode NL() { return GetToken(JavaDoc.NL, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public ITerminalNode Star() { return GetToken(JavaDoc.Star, 0); }
		[System.Diagnostics.DebuggerNonUserCode] public DocParagraphContext docParagraph() {
			return GetRuleContext<DocParagraphContext>(0);
		}
		public DocParagraphContext(ParserRuleContext parent, int invokingState)
			: base(parent, invokingState)
		{
		}
		public override int RuleIndex { get { return RULE_docParagraph; } }
		[System.Diagnostics.DebuggerNonUserCode]
		public override void EnterRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.EnterDocParagraph(this);
		}
		[System.Diagnostics.DebuggerNonUserCode]
		public override void ExitRule(IParseTreeListener listener) {
			IJavaDocListener typedListener = listener as IJavaDocListener;
			if (typedListener != null) typedListener.ExitDocParagraph(this);
		}
	}

	[RuleVersion(0)]
	public DocParagraphContext docParagraph() {
		DocParagraphContext _localctx = new DocParagraphContext(Context, State);
		EnterRule(_localctx, 14, RULE_docParagraph);
		try {
			EnterOuterAlt(_localctx, 1);
			{
			State = 102;
			docLine();
			State = 106;
			ErrorHandler.Sync(this);
			switch ( Interpreter.AdaptivePredict(TokenStream,13,Context) ) {
			case 1:
				{
				State = 103;
				Match(NL);
				State = 104;
				Match(Star);
				State = 105;
				docParagraph();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			ErrorHandler.ReportError(this, re);
			ErrorHandler.Recover(this, re);
		}
		finally {
			ExitRule();
		}
		return _localctx;
	}

	private static int[] _serializedATN = {
		4,1,24,109,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
		7,7,1,0,1,0,3,0,19,8,0,1,0,3,0,22,8,0,1,0,1,0,1,0,5,0,27,8,0,10,0,12,0,
		30,9,0,1,0,1,0,1,0,1,1,3,1,36,8,1,1,1,1,1,3,1,40,8,1,1,2,1,2,1,3,5,3,45,
		8,3,10,3,12,3,48,9,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,59,8,4,1,
		4,1,4,1,4,1,4,3,4,65,8,4,1,4,1,4,3,4,69,8,4,3,4,71,8,4,1,5,1,5,1,5,1,5,
		1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,92,8,5,
		1,6,1,6,1,6,1,6,5,6,98,8,6,10,6,12,6,101,9,6,1,7,1,7,1,7,1,7,3,7,107,8,
		7,1,7,0,0,8,0,2,4,6,8,10,12,14,0,1,1,0,6,7,123,0,16,1,0,0,0,2,35,1,0,0,
		0,4,41,1,0,0,0,6,46,1,0,0,0,8,70,1,0,0,0,10,91,1,0,0,0,12,93,1,0,0,0,14,
		102,1,0,0,0,16,18,5,23,0,0,17,19,5,21,0,0,18,17,1,0,0,0,18,19,1,0,0,0,
		19,21,1,0,0,0,20,22,3,2,1,0,21,20,1,0,0,0,21,22,1,0,0,0,22,23,1,0,0,0,
		23,28,3,6,3,0,24,25,5,22,0,0,25,27,5,21,0,0,26,24,1,0,0,0,27,30,1,0,0,
		0,28,26,1,0,0,0,28,29,1,0,0,0,29,31,1,0,0,0,30,28,1,0,0,0,31,32,5,24,0,
		0,32,33,5,0,0,1,33,1,1,0,0,0,34,36,5,22,0,0,35,34,1,0,0,0,35,36,1,0,0,
		0,36,37,1,0,0,0,37,39,3,14,7,0,38,40,5,21,0,0,39,38,1,0,0,0,39,40,1,0,
		0,0,40,3,1,0,0,0,41,42,7,0,0,0,42,5,1,0,0,0,43,45,3,8,4,0,44,43,1,0,0,
		0,45,48,1,0,0,0,46,44,1,0,0,0,46,47,1,0,0,0,47,7,1,0,0,0,48,46,1,0,0,0,
		49,50,5,22,0,0,50,51,5,21,0,0,51,52,5,22,0,0,52,53,3,14,7,0,53,54,5,21,
		0,0,54,71,1,0,0,0,55,58,5,22,0,0,56,57,5,21,0,0,57,59,5,22,0,0,58,56,1,
		0,0,0,58,59,1,0,0,0,59,60,1,0,0,0,60,61,3,10,5,0,61,62,5,21,0,0,62,71,
		1,0,0,0,63,65,5,22,0,0,64,63,1,0,0,0,64,65,1,0,0,0,65,66,1,0,0,0,66,68,
		3,4,2,0,67,69,5,21,0,0,68,67,1,0,0,0,68,69,1,0,0,0,69,71,1,0,0,0,70,49,
		1,0,0,0,70,55,1,0,0,0,70,64,1,0,0,0,71,9,1,0,0,0,72,73,5,14,0,0,73,92,
		3,14,7,0,74,75,5,15,0,0,75,76,5,19,0,0,76,92,3,14,7,0,77,78,5,13,0,0,78,
		79,5,19,0,0,79,92,3,14,7,0,80,81,5,16,0,0,81,92,5,19,0,0,82,83,5,12,0,
		0,83,84,5,19,0,0,84,92,3,14,7,0,85,92,5,11,0,0,86,87,5,17,0,0,87,92,5,
		19,0,0,88,89,5,18,0,0,89,92,3,14,7,0,90,92,5,10,0,0,91,72,1,0,0,0,91,74,
		1,0,0,0,91,77,1,0,0,0,91,80,1,0,0,0,91,82,1,0,0,0,91,85,1,0,0,0,91,86,
		1,0,0,0,91,88,1,0,0,0,91,90,1,0,0,0,92,11,1,0,0,0,93,99,5,19,0,0,94,98,
		5,19,0,0,95,98,5,22,0,0,96,98,3,10,5,0,97,94,1,0,0,0,97,95,1,0,0,0,97,
		96,1,0,0,0,98,101,1,0,0,0,99,97,1,0,0,0,99,100,1,0,0,0,100,13,1,0,0,0,
		101,99,1,0,0,0,102,106,3,12,6,0,103,104,5,21,0,0,104,105,5,22,0,0,105,
		107,3,14,7,0,106,103,1,0,0,0,106,107,1,0,0,0,107,15,1,0,0,0,14,18,21,28,
		35,39,46,58,64,68,70,91,97,99,106
	};

	public static readonly ATN _ATN =
		new ATNDeserializer().Deserialize(_serializedATN);


}