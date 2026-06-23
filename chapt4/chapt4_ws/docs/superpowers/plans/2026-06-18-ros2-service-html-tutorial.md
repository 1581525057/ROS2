# ROS 2 Service HTML Tutorial Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Build a standalone beginner-friendly HTML tutorial for ROS 2 service communication from the existing Markdown notes.

**Architecture:** Keep the Markdown file unchanged and create a new static HTML document with embedded CSS and JavaScript. The HTML page owns presentation, navigation, copy buttons, and beginner callouts; the ROS 2 commands and code remain plain text inside copyable blocks.

**Tech Stack:** Static HTML, CSS, vanilla JavaScript, ROS 2 Python tutorial content.

---

## File Structure

- Create: `service_communication_tutorial.html`
  - Standalone tutorial page.
  - Contains embedded styles, navigation, content, and copy-button behavior.
- Create: `superpowers/specs/2026-06-18-ros2-service-html-tutorial-design.md`
  - Short design record for future edits.
- Create: `superpowers/plans/2026-06-18-ros2-service-html-tutorial.md`
  - Implementation plan record.

### Task 1: Create Design And Plan Records

**Files:**
- Create: `superpowers/specs/2026-06-18-ros2-service-html-tutorial-design.md`
- Create: `superpowers/plans/2026-06-18-ros2-service-html-tutorial.md`

- [x] **Step 1: Write the design record**

Record the goal, audience, content structure, UX details, and verification criteria.

- [x] **Step 2: Write the implementation plan**

Record the target files and the concrete tasks needed to create and verify the tutorial.

### Task 2: Create The Standalone HTML Tutorial

**Files:**
- Create: `service_communication_tutorial.html`

- [x] **Step 1: Add static page structure**

Create a complete HTML document with a sidebar table of contents, main content area, and footer.

- [x] **Step 2: Add tutorial content**

Convert the Markdown lesson into structured sections with beginner explanations, command groups, Python code, XML code, and expected outputs.

- [x] **Step 3: Add CSS**

Add responsive layout, readable typography, code block styling, callouts, tables, and print-friendly behavior.

- [x] **Step 4: Add JavaScript**

Add copy buttons for code blocks and active table-of-contents highlighting.

### Task 3: Verify The Output

**Files:**
- Inspect: `service_communication_tutorial.html`

- [x] **Step 1: Check file presence**

Run: `test -f service_communication_tutorial.html`

- [x] **Step 2: Check required sections**

Run: `rg "创建 srv 接口包|服务端节点|客户端节点|节点参数|参数事件|远程修改参数|常见错误" service_communication_tutorial.html`

- [x] **Step 3: Check JavaScript syntax**

Run: `node --check service_communication_tutorial.html`

Checked by extracting the embedded script to `/tmp/ros2_service_tutorial_script.js` and running `node --check /tmp/ros2_service_tutorial_script.js`.

- [x] **Step 4: Confirm direct-open usage**

Report the absolute path so the user can open the file in a browser.
