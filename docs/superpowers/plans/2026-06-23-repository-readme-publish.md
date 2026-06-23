# Repository README and Publish Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Document every ROS 2 learning workspace in the root README and publish the current local source changes to `origin/main`.

**Architecture:** The root `README.md` becomes the repository entry point. It enumerates source workspaces and packages, gives a shared `colcon` workflow, and provides selected commands without duplicating package implementation details. Git ignore rules exclude generated ROS 2 outputs and Python cache files.

**Tech Stack:** Markdown, Git, ROS 2 Humble, `colcon`.

---

## File Structure

- Modify: `README.md` — overview, workspace index, build/run instructions, conventions, and troubleshooting.
- Verify: `.gitignore` — generated `build/`, `install/`, `log/`, and `__pycache__/` paths are ignored.
- Include: `CHATP3/topic_ws/src/demo_cpp_topic/src/turtle_circle.cpp`, `CHATP3/topic_practice_ws/src/**`, and `chapt4/chapt4_ws/src/**`.

### Task 1: Replace the root README with a repository-level guide

**Files:**
- Modify: `README.md`

- [ ] **Step 1: Map package names and executable entry points**

Run: `rg -n 'add_executable|console_scripts' CHAPT2/chapt2_ws/src CHATP3/topic_ws/src CHATP3/topic_practice_ws/src chapt4/chapt4_ws/src -g 'CMakeLists.txt' -g 'setup.py'`

Expected: the output identifies the C++ executables and Python console scripts used in the README.

- [ ] **Step 2: Write the README sections**

Add the sections `Learning Modules`, `Prerequisites`, `Build a Workspace`, `Run Examples`, `Repository Conventions`, and `Troubleshooting`. The workspace table must cover `CHAPT2/chapt2_ws`, `CHATP3/topic_ws`, `CHATP3/topic_practice_ws`, and `chapt4/chapt4_ws`. The shared build command must include `source /opt/ros/humble/setup.bash`, `colcon build`, and `source install/setup.bash`.

- [ ] **Step 3: Validate documentation references**

Run: `git diff --check && test -d CHAPT2/chapt2_ws/src && test -d CHATP3/topic_ws/src && test -d CHATP3/topic_practice_ws/src && test -d chapt4/chapt4_ws/src`

Expected: exit status `0` with no whitespace errors.

### Task 2: Stage and commit intended files

**Files:**
- Verify: `.gitignore`
- Include: `README.md`, `CHATP3/topic_ws/src/demo_cpp_topic/src/turtle_circle.cpp`, `CHATP3/topic_practice_ws/src`, `chapt4/chapt4_ws/src`

- [ ] **Step 1: Confirm generated output remains ignored**

Run: `git check-ignore -v chapt4/chapt4_ws/build chapt4/chapt4_ws/install chapt4/chapt4_ws/log chapt4/chapt4_ws/src/patrol_service_demo/patrol_service_demo/__pycache__/patrol_server.cpython-310.pyc`

Expected: every supplied path is reported as ignored by `.gitignore`.

- [ ] **Step 2: Stage only documentation and source**

Run: `git add README.md CHATP3/topic_ws/src/demo_cpp_topic/src/turtle_circle.cpp CHATP3/topic_practice_ws/src chapt4/chapt4_ws/src && git status --short`

Expected: no generated `build/`, `install/`, `log/`, `__pycache__/`, or `*.pyc` paths are staged.

- [ ] **Step 3: Inspect and commit the staged change**

Run: `git diff --cached --check && git diff --cached --stat && git commit -m "feat: add topic practice and patrol service examples"`

Expected: no whitespace errors; the commit contains intended source and README files only.

### Task 3: Push and confirm GitHub synchronization

**Files:**
- No file changes.

- [ ] **Step 1: Check the branch before publication**

Run: `git status --short --branch && git log --oneline origin/main..main`

Expected: the intended local commits are listed and no unexpected files remain.

- [ ] **Step 2: Publish `main`**

Run: `git push origin main`

Expected: GitHub accepts the new commits.

- [ ] **Step 3: Confirm synchronization**

Run: `git fetch origin && git status --short --branch`

Expected: `main` is synchronized with `origin/main`.
